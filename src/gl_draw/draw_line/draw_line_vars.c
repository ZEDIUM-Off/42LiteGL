/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:16:10 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/28 17:02:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

typedef struct draw_line_shader_vars
{
	float	x[2];
	float	y[2];
	float	z[2];
	float	w[2];
	float	slope;
	t_Line	line;
	float	t;
	float	lx;
	float	ly;
	float	lz;
	float	lw;
	float	lh;
	t_vec2	p[2];
	t_vec2	pr;
	t_vec2	sub_p;
	t_vec2	ab;
	float	i_x[2];
	float	i_y[2];
	float	x_mima[2];
	float	y_mima[2];
	float	line_len_sq;
	int		diag;
	int		first_is_diag;
}	t_draw_line_shader_vars;

void	left_right(t_draw_line_shader_vars *vars, float ***v_out)
{
	float	tmp;
	float	*tmp_ptr;

	if (vars->x[0] > vars->x[1])
	{
		tmp = vars->x[0];
		vars->x[0] = vars->x[1];
		vars->x[1] = tmp;
		tmp = vars->y[0];
		vars->y[0] = vars->y[1];
		vars->y[1] = tmp;
		tmp = vars->z[0];
		vars->z[0] = vars->z[1];
		vars->z[1] = tmp;
		tmp = vars->w[0];
		vars->w[0] = vars->w[1];
		vars->w[1] = tmp;
		tmp_ptr = *v_out[0];
		*v_out[0] = *v_out[1];
		*v_out[1] = tmp_ptr;
	}
}

void	mima_left_right(t_draw_line_shader_vars *vars)
{
	if (vars->slope <= 0)
	{
		vars->y_mima[0] = vars->i_y[1];
		vars->y_mima[1] = vars->i_y[0];
	}
	else
	{
		vars->y_mima[0] = vars->i_y[0];
		vars->y_mima[1] = vars->i_y[1];
	}
}

void	set_line_shader_vars(t_GLContext *c, t_draw_line_shader_vars *vars,
	t_vec4 *vertexes, float ***v_out)
{
	vars->x = {vertexes[0].x, vertexes[1].x};
	vars->y = {vertexes[0].y, vertexes[1].y};
	vars->z = {vertexes[0].z, vertexes[1].z};
	vars->w = {vertexes[0].w, vertexes[1].w};
	left_right(vars, &v_out);
	vars.slope = (vars.y[1] - vars.y[0]) / (vars.x[1] - vars.x[0]);
	vars.line = make_line(vars.x[0], vars.y[0], vars.x[1], vars.y[1]);
	vars->ab = scale_vec2(
			normalize_vec2({vars->line.a, vars->line.b}), c->line_width / 2);
	vars->p[0] = {vars->x[0], vars->y[0]};
	vars->p[1] = {vars->x[1], vars->y[1]};
	vars->sub_p = sub_vec2(vars->p[1], vars->p[0]);
	vars->line_len_sq = length_vec2(vars->sub_p);
	vars->line_len_sq *= vars->line_len_sq;
	vars->i_x[0] = floor(vars->p[0].x) + 0.5;
	vars->i_x[1] = floor(vars->p[1].x) + 0.5;
	vars->i_y[0] = floor(vars->p[0].y) + 0.5;
	vars->i_y[1] = floor(vars->p[1].y) + 0.5;
	vars->x_mima[0] = vars->i_x[0];
	vars->x_mima[1] = vars->i_x[1];
	mima_left_right(vars);
	vars->z[0] = map(vars->z[0], -1.0f, 1.0f, c->depth_range_near,
			c->depth_range_far);
	vars->z[1] = map(vars->z[1], -1.0f, 1.0f, c->depth_range_near,
			c->depth_range_far);
}

void	set_perp_line_vars(
	t_GLContext *c, t_draw_line_shader_vars *vars, float *vx, float *vy)
{
	vars->line = make_line(vars->x[0], vars->y[0], vars->x[1], vars->y[1]);
	vars->i_x[0] = floor(vars->x[0]) + 0.5;
	vars->i_x[1] = floor(vars->x[1]) + 0.5;
	vars->i_y[0] = floor(vars->y[0]) + 0.5;
	vars->i_y[1] = floor(vars->y[1]) + 0.5;
	vars->x_mima[0] = vars->i_x[0];
	vars->x_mima[1] = vars->i_x[1];
	mima_left_right(vars);
	vars->lz = c->builtins.glFragCoord.z;
	vars->lw = c->back_buffer.w;
	vars->lh = c->back_buffer.h;
	vars->first_is_diag = GL_FALSE;
}
