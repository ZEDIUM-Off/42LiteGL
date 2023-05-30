/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_multi_draw_arrays.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:50:02 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/25 14:21:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_multi_draw_arrays(
	t_gl_context *c, t_gl_enum mode, t_multi_draw_arrays_settings *sett)
{
	t_gl_sizei			i;
	t_pipeline_settings	settings;

	if (mode < GL_POINTS || mode > GL_TRIANGLE_FAN)
		return (set_err(c, GL_INVALID_ENUM));
	if (sett->drawcount < 0)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	i = 0;
	while (i < sett->drawcount)
	{
		if (!sett->count[i])
		{
			i++;
			continue ;
		}
		settings = (t_pipeline_settings){mode, sett->first[i],
			sett->count[i], 0, 0, GL_FALSE};
		run_pipeline(c, &settings);
		i++;
	}
}
