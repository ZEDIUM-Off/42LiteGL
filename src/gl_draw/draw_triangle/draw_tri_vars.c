/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tri_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:52:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:23:43 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

#define SMALL_INCR 0.000001;

typedef struct s_draw_tri_vars
{
	t_Shader_Builtins	builtins;
	t_vec3				h[3];
	float				dzxy[6];
	float				max_depth_slope;
	float				poly_offset;
	float				x_mima[2];
	float				y_mima[2];
	int					i_xy_max[2];
	t_Line				lines[3];
	float				alpha;
	float				beta;
	float				gamma;
	float				fs_input[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	float				perspective[GL_MAX_VERTEX_OUTPUT_COMPONENTS * 3];
	float				*vs_output;
	float				x;
	float				y;
	float				z;
	float				tmp;
	float				tmp2;
	float				ix;
	float				iy;
}				t_draw_tri_vars;

typedef struct s_draw_tri_clip_vars
{
	t_glVertex	tmp1;
	t_glVertex	tmp2;
	t_glVertex	*new_v[3];
	float		tt;
	float		tmp1_out[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	float		tmp2_out[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	int			edge_flag_tmp;
}	t_draw_tri_clip_vars;

void	set_draw_tri_clip_vars(t_draw_tri_clip_vars *vars)
{
	vars->tmp1.vs_out = vars->tmp1_out;
	vars->tmp2.vs_out = vars->tmp2_out;
}

void	set_dzxy_max_slope(t_GLContext *c, t_draw_tri_vars *vars)
{
	int	i;

	if (c->poly_offset)
	{
		vars->dzxy[0] = fabsf((vars->h[1].z - vars->h[0].z)
				/ (vars->h[1].x - vars->h[0].x));
		vars->dzxy[1] = fabsf((vars->h[1].z - vars->h[0].z)
				/ (vars->h[1].y - vars->h[0].y));
		vars->dzxy[2] = fabsf((vars->h[2].z - vars->h[1].z)
				/ (vars->h[2].x - vars->h[1].x));
		vars->dzxy[3] = fabsf((vars->h[2].z - vars->h[1].z)
				/ (vars->h[2].y - vars->h[1].y));
		vars->dzxy[4] = fabsf((vars->h[0].z - vars->h[2].z)
				/ (vars->h[0].x - vars->h[2].x));
		vars->dzxy[5] = fabsf((vars->h[0].z - vars->h[2].z)
				/ (vars->h[0].y - vars->h[2].y));
		vars->max_depth_slope = vars->dzxy[0];
		i = 1;
		while (i < 6)
		{
			if (vars->dzxy[i] > vars->max_depth_slope)
				vars->max_depth_slope = vars->dzxy[i];
			i++;
		}
	}
}

void	set_perspective(t_GLContext *c, t_draw_tri_vars *vars, t_glVertex **v)
{
	int	i;

	i = 0;
	while (i < c->vs_output.size)
	{
		vars->perspective[i] = v[0]->vs_out[i] / v[0]->screen_space.w;
		vars->perspective[GL_MAX_VERTEX_OUTPUT_COMPONENTS + i] = \
			v[1]->vs_out[i] / v[1]->screen_space.w;
		vars->perspective[GL_MAX_VERTEX_OUTPUT_COMPONENTS * 2 + i] = \
			v[2]->vs_out[i] / v[2]->screen_space.w;
		i++;
	}
}

void	set_draw_tri_vars(t_GLContext *c, t_draw_tri_vars *vars, t_glVertex **v)
{
	vars->h[0] = vec4_to_vec3h(v[0]->screen_space);
	vars->h[1] = vec4_to_vec3h(v[1]->screen_space);
	vars->h[2] = vec4_to_vec3h(v[2]->screen_space);
	set_dzxy_max_slope(vars);
	vars->poly_offset = vars->max_depth_slope
		* c->poly_factor + c->poly_units * SMALL_INCR;
	vars->x_mima[0] = fmin(vars->h[0].x, fmin(vars->h[1].x, vars->h[2].x));
	vars->x_mima[1] = fmax(vars->h[0].x, fmax(vars->h[1].x, vars->h[2].x));
	vars->y_mima[0] = fmin(vars->h[0].y, fmin(vars->h[1].y, vars->h[2].y));
	vars->y_mima[1] = fmax(vars->h[0].y, fmax(vars->h[1].y, vars->h[2].y));
	vars->i_xy_max[0] = roundf(vars->x_mima[1]);
	vars->i_xy_max[1] = roundf(vars->y_mima[1]);
	lines = {make_line(vars->h[0].x, vars->h[0].y, vars->h[1].x, vars->h[1].y),
		make_line(vars->h[1].x, vars->h[1].y, vars->h[2].x, vars->h[2].y),
		make_line(vars->h[2].x, vars->h[2].y, vars->h[0].x, vars->h[0].y)};
	vars->vs_output = &c->vs_output.output_buf.a[0];
	set_perspective(c, vars, v);
}
