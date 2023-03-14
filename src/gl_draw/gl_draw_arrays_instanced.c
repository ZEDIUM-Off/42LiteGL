/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw_arrays_instanced.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:50:53 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 15:26:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_draw_arrays_instanced(
	t_gl_context *c, t_gl_enum mode, t_draw_arrays_instanced_settings *sett)
{
	t_gl_sizei			i;
	t_pipeline_settings	settings;

	if (mode < GL_POINTS || mode > GL_TRIANGLE_FAN)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (sett->count < 0 || sett->instancecount < 0)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	if (!sett->count || !sett->instancecount)
		return ;
	i = 0;
	while (i < sett->instancecount)
	{
		settings = (t_pipeline_settings){mode, sett->first,
			sett->count, i, 0, GL_FALSE};
		run_pipeline(c, &settings);
		i++;
	}
}
