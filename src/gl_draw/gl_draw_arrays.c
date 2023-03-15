/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:17:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 15:13:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_draw_arrays(t_gl_context *c,
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
