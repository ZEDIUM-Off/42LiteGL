/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_multi_draw_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:36:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_multi_draw_elements(
	t_gl_context *c, t_gl_enum mode, t_multi_draw_elements_settings *sett)
{
	t_gl_sizei			i;
	t_pipeline_settings	settings;

	if (mode < GL_POINTS || mode > GL_TRIANGLE_FAN)
		return (if (!c->error) c->error = GL_INVALID_ENUM);
	if (sett->drawcount < 0)
		return (if (!c->error) c->error = GL_INVALID_VALUE);
	if (sett->type != GL_UNSIGNED_BYTE && sett->type != GL_UNSIGNED_SHORT
		&& sett->type != GL_UNSIGNED_INT)
		return (if (!c->error) c->error = GL_INVALID_ENUM);
	c->buffers.a[c->vertex_arrays.a[c->cur_vertex_array].element_buffer].type = \
	sett->type;
	i = 0;
	while (i < sett->drawcount)
	{
		if (!sett->count[i])
		{
			i++;
			continue ;
		}
		settings = {mode, sett->indices[i], sett->count[i], 0, 0, GL_TRUE};
		run_pipeline(c, &settings);
		i++;
	}
}
