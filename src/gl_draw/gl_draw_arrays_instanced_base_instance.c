/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw_arrays_instanced_base_instance.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:56:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 14:02:29 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_draw_arrays_instanced_base_instance(
	t_gl_context *c, t_gl_enum mode, t_draw_arrays_instanced_settings*sett)
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
	if (!count || !sett->instancecount)
		return ;
	i = 0;
	while (i < sett->instancecount)
	{
		settings = {mode, sett->first, sett->count,
			i, sett->baseinstance, GL_FALSE};
		run_pipeline(c, &settings);
		i++;
	}
}
