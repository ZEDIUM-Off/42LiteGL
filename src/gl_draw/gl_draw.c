/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:17:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 12:41:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	run_pipeline(t_GLContext *c, t_pipeline_settings *settings)
{
	ft_assert(settings->count <= MAX_VERTICES);
	vertex_stage(settings);
	if (settings->mode == GL_POINTS)
		point_mode(c, settings->first, settings->count);
	else if (settings->mode == GL_LINES)
		line_mode(c, settings->first, settings->count);
	else if (settings->mode == GL_LINE_STRIP)
		line_strip_mode(c, settings->first, settings->count);
	else if (settings->mode == GL_LINE_LOOP)
		line_loop_mode(c, settings->first, settings->count);
	else if (settings->mode == GL_TRIANGLES)
		triangle_mode(c, settings->first, settings->count);
	else if (settings->mode == GL_TRIANGLE_STRIP)
		triangle_strip_mode(c, settings->count);
	else if (settings->mode == GL_TRIANGLE_FAN)
		triangle_fan_mode(c, settings->count);
}

void	gl_draw_arrays(t_GLContext *c,
	t_gl_enum mode, t_gl_int first, t_gl_sizei count)
{
	t_pipeline_settings	settings;

	if (mode < GL_POINTS || mode > GL_TRIANGLE_FAN)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (count < 0)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	if (!count)
		return ;
	settings = (t_pipeline_settings){mode, first, count, 0, 0, GL_FALSE};
	run_pipeline(c, &settings);
}
