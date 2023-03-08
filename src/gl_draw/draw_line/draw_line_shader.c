/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_shader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:49:57 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/28 17:15:32 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	draw_line_shader_slope_less_minuss_one(
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
		set_vec4(c->builtins.gl_FragCoord,
			vars->lx, vars->ly, vars->lz, 1 / vars->lw);
		c->builtins.discard = GL_FALSE;
		c->builtins.gl_FragDepth = vars->lz;
		setup_fs_input(c, v_out, vars, provoke);
		c->programs.a[c->programs.cur_program].fragment_shader(c->fs_input,
			&c->builtins, c->programs.a[c->programs.cur_program].uniform);
		if (!c->builtins.discard)
			draw_pixel(c, c->builtins.gl_FragColor,
			{vars->lx, vars->ly}, c->builtins.gl_FragDepth);
		if (line_func(&vars->line, vars->lx + 0.5f, vars->ly - 1) < 0)
			vars->lx++;
		vars->ly--;
	}
}

void	draw_line_shader_slope_less_zero(
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
		set_vec4(c->builtins.gl_FragCoord,
			vars->lx, vars->ly, vars->lz, 1 / vars->lw);
		c->builtins.discard = GL_FALSE;
		c->builtins.gl_FragDepth = vars->lz;
		setup_fs_input(c, v_out, vars, provoke);
		c->programs.a[c->programs.cur_program].fragment_shader(c->fs_input,
			&c->builtins, c->programs.a[c->programs.cur_program].uniform);
		if (!c->builtins.discard)
			draw_pixel(c, c->builtins.gl_FragColor,
			{vars->lx, vars->ly}, c->builtins.gl_FragDepth);
		if (line_func(&vars->line, vars->lx + 1, vars->ly - 0.5f) > 0)
			vars->ly--;
		vars->lx++;
	}
}

void	draw_line_shader_slope_less_one(
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
		set_vec4(c->builtins.gl_FragCoord,
			vars->lx, vars->ly, vars->lz, 1 / vars->lw);
		c->builtins.discard = GL_FALSE;
		c->builtins.gl_FragDepth = vars->lz;
		setup_fs_input(c, v_out, vars, provoke);
		c->programs.a[c->programs.cur_program].fragment_shader(c->fs_input,
			&c->builtins, c->programs.a[c->programs.cur_program].uniform);
		if (!c->builtins.discard)
			draw_pixel(c, c->builtins.gl_FragColor,
			{vars->lx, vars->ly}, c->builtins.gl_FragDepth);
		if (line_func(&vars->line, vars->lx + 1, vars->ly + 0.5f) < 0)
			vars->ly++;
		vars->lx++;
	}
}

void	draw_line_shader_slope_more_one(
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
		set_vec4(c->builtins.gl_FragCoord,
			vars->lx, vars->ly, vars->lz, 1 / vars->lw);
		c->builtins.discard = GL_FALSE;
		c->builtins.gl_FragDepth = vars->lz;
		setup_fs_input(c, v_out, vars, provoke);
		c->programs.a[c->programs.cur_program].fragment_shader(c->fs_input,
			&c->builtins, c->programs.a[c->programs.cur_program].uniform);
		if (!c->builtins.discard)
			draw_pixel(c, c->builtins.gl_FragColor,
			{vars->lx, vars->ly}, c->builtins.gl_FragDepth);
		if (line_func(&vars->line, vars->lx + 0.5f, vars->ly + 1) > 0)
			vars->lx++;
		vars->ly++;
	}
}

void	draw_line_shader(t_GLContext *c, t_vec4 *vertexes, float **v_out,
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
