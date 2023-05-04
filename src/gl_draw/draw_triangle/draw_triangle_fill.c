/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:45:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/04 12:17:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	draw_tri_action_finish(
	t_gl_context *c, t_draw_tri_vars *vars)
{
	set_vec4(&vars->builtins.gl_frag_coord,
		(float [4]){vars->x, vars->y, vars->z, vars->tmp2});
	vars->builtins.discard = GL_FALSE;
	vars->builtins.gl_frag_depth = vars->z;
	vars->builtins.gl_instance_id = c->builtins.gl_instance_id;
	c->programs.a[c->cur_program].fragment_shader(vars->fs_input,
		&vars->builtins, c->programs.a[c->cur_program].uniform);
	if (!vars->builtins.discard)
		draw_pixel(c, vars->builtins.gl_frag_color, (t_vec2){vars->x, vars->y},
			vars->builtins.gl_frag_depth);
}

void	draw_tri_action_next(
	t_gl_context *c, t_draw_tri_vars *vars, t_gl_vertex **v,
	unsigned int provoke)
{
	int	i;

	i = 0;
	while (i < c->vs_output.size)
	{
		if (c->vs_output.interpolation[i] == SMOOTH)
		{
			vars->tmp = vars->alpha * vars->perspective[i]
				+ vars->beta
				* vars->perspective[i + GL_MAX_VERTEX_OUTPUT_COMPONENTS]
				+ vars->gamma
				* vars->perspective[i + GL_MAX_VERTEX_OUTPUT_COMPONENTS * 2];
			vars->fs_input[i] = vars->tmp / vars->tmp2;
		}
		else if (c->vs_output.interpolation[i] == NOPERSPECTIVE)
			vars->fs_input[i] = vars->alpha * v[0]->vs_out[i]
				+ vars->beta * v[1]->vs_out[i]
				+ vars->gamma * v[2]->vs_out[i];
		else
			vars->fs_input[i] = vars->vs_output[
				provoke * c->vs_output.size + i];
		i++;
	}
	draw_tri_action_finish(c, vars);
}

void	draw_tri_action(
	t_gl_context *c, t_draw_tri_vars *vars, t_gl_vertex **v,
	unsigned int provoke)
{
	if ((vars->alpha > 0
			|| line_func(&vars->lines[1], vars->h[0].x, vars->h[0].y)
			* line_func(&vars->lines[1], -1, -2.5) > 0)
		&& (vars->beta > 0
			|| line_func(&vars->lines[2], vars->h[1].x, vars->h[1].y)
			* line_func(&vars->lines[2], -1, -2.5) > 0)
		&& (vars->gamma > 0
			|| line_func(&vars->lines[0], vars->h[2].x, vars->h[2].y)
			* line_func(&vars->lines[0], -1, -2.5) > 0))
	{
		vars->tmp2 = vars->alpha * (1 / v[0]->screen_space.w)
			+ vars->beta * (1 / v[1]->screen_space.w)
			+ vars->gamma * (1 / v[2]->screen_space.w);
		vars->z = vars->alpha * vars->h[0].z
			+ vars->beta * vars->h[1].z
			+ vars->gamma * vars->h[2].z;
		vars->z = map(vars->z, c->depth_range_near, c->depth_range_far);
		vars->z += vars->poly_offset;
		draw_tri_action_next(c, vars, v, provoke);
	}
}

void	draw_triangle_fill(t_gl_context *c, t_gl_vertex **v,
unsigned int provoke)
{
	t_draw_tri_vars	vars;

	set_draw_tri_vars(c, &vars, v);
	vars.iy = vars.y_mima[0];
	while (vars.iy < vars.i_xy_max[1])
	{
		vars.y = vars.iy + 0.5f;
		vars.ix = vars.x_mima[0];
		while (vars.ix < vars.i_xy_max[0])
		{
			vars.x = vars.ix + 0.5f;
			vars.gamma = line_func(&vars.lines[0], vars.x, vars.y)
				/ line_func(&vars.lines[0], vars.h[2].x, vars.h[2].y);
			vars.beta = line_func(&vars.lines[2], vars.x, vars.y)
				/ line_func(&vars.lines[2], vars.h[1].x, vars.h[1].y);
			vars.alpha = 1 - vars.beta - vars.gamma;
			if (vars.alpha >= 0 && vars.beta >= 0 && vars.gamma >= 0)
				draw_tri_action(c, &vars, v, provoke);
			vars.ix++;
		}
		vars.iy++;
	}
}
