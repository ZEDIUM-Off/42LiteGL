/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_perp_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:39:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/28 17:25:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	draw_perp_line_slope_less_minus_one(
	t_GLContext *c, t_draw_line_shader_vars *vars)
{
	if (line_func(&vars->line, vars->x_mima[0] + 0.5f, vars->y_mima[1] - 1) < 0)
		vars->first_is_diag = GL_TRUE;
	vars->lx = vars->x_mima[0];
	vars->ly = vars->y_mima[1];
	while (vars->lx <= x_mima[1] && vars->ly >= vars->y_mima[0])
	{
		if (vars->lx >= 0 && vars->lx < vars->lw
			&& vars->ly >= 0 && vars->ly < vars->lh)
		{
			c->builtins.gl_FragCoord.x = vars->lx;
			c->builtins.gl_FragCoord.y = vars->ly;
			c->builtins.discard = GL_FALSE;
			c->builtins.gl_FragDepth = vars->lz;
			c->programs.a[c->programs.cur_program].fragment_shader(c->fs_input,
				&c->builtins, c->programs.a[c->programs.cur_program].uniform);
			if (!c->builtins.discard)
				draw_pixel(c, c->builtins.gl_FragColor,
				{vars->lx, vars->ly}, c->builtins.gl_FragDepth);
		}
		if (line_func(&vars->line, vars->lx + 0.5f, vars->ly - 1) < 0)
			vars->lx++;
		vars->ly--;
	}
}

void	draw_perp_line_slop_less_zero(
	t_GLContext *c, t_draw_line_shader_vars *vars)
{
	if (line_func(&vars->line, vars->x_mima[0] + 1, vars->y_mima[1] - 0.5f) > 0)
		vars->first_is_diag = GL_TRUE;
	vars->lx = vars->x_mima[0];
	vars->ly = vars->y_mima[1];
	while (vars->lx <= vars->x_mima[1] && vars->ly >= vars->y_mima[0])
	{
		if (vars->lx >= 0 && vars->lx < vars->lw
			&& vars->ly >= 0 && vars->ly < vars->lh)
		{
			c->builtins.gl_FragCoord.x = vars->lx;
			c->builtins.gl_FragCoord.y = vars->ly;
			c->builtins.discard = GL_FALSE;
			c->builtins.gl_FragDepth = vars->lz;
			c->programs.a[c->programs.cur_program].fragment_shader(c->fs_input,
				&c->builtins, c->programs.a[c->programs.cur_program].uniform);
			if (!c->builtins.discard)
				draw_pixel(c, c->builtins.gl_FragColor,
				{vars->lx, vars->ly}, c->builtins.gl_FragDepth);
		}
		if (line_func(&vars->line, vars->lx + 1, vars->ly - 0.5f) > 0)
			vars->ly--;
		vars->lx++;
	}
}

void	draw_perp_line_slope_less_one(
	t_GLContext *c, t_draw_line_shader_vars *vars)
{
	if (line_func(&vars->line, vars->x_mima[0] + 1, vars->y_mima[1] + 0.5f) < 0)
		vars->first_is_diag = GL_TRUE;
	vars->lx = vars->x_mima[0];
	vars->ly = vars->y_mima[0];
	while (vars->lx <= vars->x_mima[1] && vars->ly <= vars->y_mima[1])
	{
		if (vars->lx >= 0 && vars->lx < vars->lw
			&& vars->ly >= 0 && vars->ly < vars->lh)
		{
			c->builtins.gl_FragCoord.x = vars->lx;
			c->builtins.gl_FragCoord.y = vars->ly;
			c->builtins.discard = GL_FALSE;
			c->builtins.gl_FragDepth = vars->lz;
			c->programs.a[c->programs.cur_program].fragment_shader(c->fs_input,
				&c->builtins, c->programs.a[c->programs.cur_program].uniform);
			if (!c->builtins.discard)
				draw_pixel(c, c->builtins.gl_FragColor,
				{vars->lx, vars->ly}, c->builtins.gl_FragDepth);
		}
		if (line_func(&vars->line, vars->lx + 1, vars->ly + 0.5f) < 0)
			vars->ly++;
		vars->lx++;
	}
}

void	draw_perp_line_slope_more_one(
	t_GLContext *c, t_draw_line_shader_vars *vars)
{
	if (line_func(&vars->line, vars->x_mima[0] + 0.5f, vars->y_mima[0] + 1) > 0)
		vars->first_is_diag = GL_TRUE;
	vars->lx = vars->x_mima[0];
	vars->ly = vars->y_mima[0];
	while (vars->lx <= vars->x_mima[1] && vars->ly <= vars->y_mima[1])
	{
		if (vars->lx >= 0 && vars->lx < vars->lw
			&& vars->ly >= 0 && vars->ly < vars->lh)
		{
			c->builtins.gl_FragCoord.x = vars->lx;
			c->builtins.gl_FragCoord.y = vars->ly;
			c->builtins.discard = GL_FALSE;
			c->builtins.gl_FragDepth = vars->lz;
			c->programs.a[c->programs.cur_program].fragment_shader(c->fs_input,
				&c->builtins, c->programs.a[c->programs.cur_program].uniform);
			if (!c->builtins.discard)
				draw_pixel(c, c->builtins.gl_FragColor,
				{vars->lx, vars->ly}, c->builtins.gl_FragDepth);
		}
		if (line_func(&vars->line, vars->lx + 0.5f, vars->ly + 1) > 0)
			vars->lx++;
		vars->ly++;
	}
}

int	draw_perp_line(t_GLContext *c, float slope, float *vx, float *vy)
{
	t_draw_line_shader_vars	vars;

	vars.slope = slope;
	set_perp_line_vars(c, &vars, vx, vy);
	if (slope <= -1)
		draw_perp_line_slope_less_minus_one(c, &vars);
	else if (slope <= 0)
		draw_perp_line_slope_less_zero(c, &vars);
	else if (slope <= 1)
		draw_perp_line_slope_less_one(c, &vars);
	else
		draw_perp_line_slope_more_one(c, &vars);
	return (vars.first_is_diag);
}
