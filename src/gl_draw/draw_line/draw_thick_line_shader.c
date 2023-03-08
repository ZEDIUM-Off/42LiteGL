/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_thick_line_shader.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:04:31 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/28 16:51:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	draw_thick_line_shader_slope_less_minus_one(
	t_GLContext *c, t_draw_line_shader_vars *vars, float **v_out,
	unsigned int provoke)
{
	vars->lx = vars->x_mima[0];
	vars->ly = vars->y_mima[1];
	while (vars->lx <= vars->x_mima[1] && vars->ly >= vars->y_mima[0])
	{
		vars->pr = {vars->lx, vars->ly};
		vars->t = dot_vec2s(sub_vec2s(pr, p[0]), vars->sub_p)
			/ vars->line_len_sq;
		vars->lz = (1 - vars->t) * vars->z[0] + vars->t * vars->z[1];
		vars->lw = (1 - vars->t) * vars->w[0] + vars->t * vars->w[1];
		c->builtins.gl_FragCoord = {.z = vars->lz, .w = 1 / vars->lw};
		setup_fs_input(c, v_out, vars, provoke);
		vars->diag = draw_perp_line(c, -1 / vars->slope,
			{vars->lx - vars->ab.x, vars->lx + vars->abs.x},
			{vars->ly - vars->ab.y, vars->ly + vars->abs.y});
		if (line_func(&vars->line, vars->lx + 0.5f, vars->ly + 0.5f) < 0)
		{
			if (vars->diag)
				draw_perp_line(c, -1 / vars->slope,
				{vars->lx - vars->ab.x, vars->lx + vars->abs.x},
				{vars->ly - 1 - vars->ab.y, vars->ly - 1 + vars->abs.y});
			vars->lx++;
		}
		vars->ly--;
	}
}

void	draw_thick_line_shader_slope_less_zero(
	t_GLContext *c, t_draw_line_shader_vars *vars, float **v_out,
	unsigned int provoke)
{
	vars->lx = vars->x_mima[0];
	vars->ly = vars->y_mima[1];
	while (vars->lx <= vars->x_mima[1] && vars->ly >= vars->y_mima[0])
	{
		vars->pr = {vars->lx, vars->ly};
		vars->t = dot_vec2s(sub_vec2s(pr, p[0]), vars->sub_p)
			/ vars->line_len_sq;
		vars->lz = (1 - vars->t) * vars->z[0] + vars->t * vars->z[1];
		vars->lw = (1 - vars->t) * vars->w[0] + vars->t * vars->w[1];
		c->builtins.gl_FragCoord = {.z = vars->lz, .w = 1 / vars->lw};
		setup_fs_input(c, v_out, vars, provoke);
		vars->diag = draw_perp_line(c, -1 / vars->slope,
			{vars->lx - vars->ab.x, vars->lx + vars->abs.x},
			{vars->ly - vars->ab.y, vars->ly + vars->abs.y});
		if (line_func(&vars->line, vars->lx + 1, vars->ly - 0.5f) > 0)
		{
			if (vars->diag)
				draw_perp_line(c, -1 / vars->slope,
				{vars->lx + 1 - vars->ab.x, vars->lx + 1 + vars->abs.x},
				{vars->ly - vars->ab.y, vars->ly + vars->abs.y});
			vars->ly--;
		}
		vars->lx++;
	}
}

void	draw_thick_line_shader_slope_less_one(
	t_GLContext *c, t_draw_line_shader_vars *vars, float **v_out,
	unsigned int provoke)
{
	vars->lx = vars->x_mima[0];
	vars->ly = vars->y_mima[0];
	while (vars->lx <= vars->x_mima[1] && vars->ly <= vars->y_mima[1])
	{
		vars->pr = {vars->lx, vars->ly};
		vars->t = dot_vec2s(sub_vec2s(pr, p[0]), vars->sub_p)
			/ vars->line_len_sq;
		vars->lz = (1 - vars->t) * vars->z[0] + vars->t * vars->z[1];
		vars->lw = (1 - vars->t) * vars->w[0] + vars->t * vars->w[1];
		c->builtins.gl_FragCoord = {.z = vars->lz, .w = 1 / vars->lw};
		setup_fs_input(c, v_out, vars, provoke);
		vars->diag = draw_perp_line(c, -1 / vars->slope,
			{vars->lx + vars->ab.x, vars->lx - vars->abs.x},
			{vars->ly + vars->ab.y, vars->ly - vars->abs.y});
		if (line_func(&vars->line, vars->lx + 1, vars->ly + 0.5f) < 0)
		{
			if (vars->diag)
				draw_perp_line(c, -1 / vars->slope,
				{vars->lx + 1 + vars->ab.x, vars->lx + 1 - vars->abs.x},
				{vars->ly + vars->ab.y, vars->ly - vars->abs.y});
			vars->ly++;
		}
		vars->lx++;
	}
}

void	draw_thick_line_shader_slope_more_one(
	t_GLContext *c, t_draw_line_shader_vars *vars, float **v_out,
	unsigned int provoke)
{
	vars->lx = vars->x_mima[0];
	vars->ly = vars->y_mima[0];
	while (vars->lx <= vars->x_mima[1] && vars->ly <= vars->y_mima[1])
	{
		vars->pr = {vars->lx, vars->ly};
		vars->t = dot_vec2s(sub_vec2s(pr, p[0]), vars->sub_p)
			/ vars->line_len_sq;
		vars->lz = (1 - vars->t) * vars->z[0] + vars->t * vars->z[1];
		vars->lw = (1 - vars->t) * vars->w[0] + vars->t * vars->w[1];
		c->builtins.gl_FragCoord = {.z = vars->lz, .w = 1 / vars->lw};
		setup_fs_input(c, v_out, vars, provoke);
		vars->diag = draw_perp_line(c, -1 / vars->slope,
			{vars->lx + vars->ab.x, vars->lx - vars->abs.x},
			{vars->ly + vars->ab.y, vars->ly - vars->abs.y});
		if (line_func(&vars->line, vars->lx + 0.5f, vars->ly + 1) > 0)
		{
			if (vars->diag)
				draw_perp_line(c, -1 / vars->slope,
				{vars->lx + vars->ab.x, vars->lx - vars->abs.x},
				{vars->ly + 1 + vars->ab.y, vars->ly + 1 - vars->abs.y});
			vars->lx++;
		}
		vars->ly++;
	}
}

void	draw_thick_line_shader(t_GLContext *c, t_vec4 *vertexes, float **v_out,
	unsigned int provoke)
{
	t_draw_line_shader_vars	vars;

	set_vars(c, &vars, vertexes, &v_out);
	if (vars->slope <= -1)
		draw_line_shader_slope_less_minus_one(c, &vars, v_out, provoke);
	else if (vars->slope <= 0)
		draw_line_shader_slope_less_zero(c, &vars, v_out, provoke);
	else if (vars->slope <= 1)
		draw_line_shader_slope_less_one(c, &vars, v_out, provoke);
	else
		draw_line_shader_slope_more_one(c, &vars, v_out, provoke);
}
