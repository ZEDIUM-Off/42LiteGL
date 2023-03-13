/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:49:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	run_pipeline(t_gl_context *c, t_pipeline_settings *settings)
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
