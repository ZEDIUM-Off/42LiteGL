/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:57:53 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_draw_elements(
	t_gl_context *c, t_gl_enum mode, t_draw_elements_settings *sett)
{
	t_pipeline_settings	settings;

	if (mode < GL_POINTS || mode > GL_TRIANGLE_FAN)
		return (if (!c->error) c->error = GL_INVALID_ENUM);
	if (sett->type != GL_UNSIGNED_BYTE && sett->type != GL_UNSIGNED_SHORT
		&& sett->type != GL_UNSIGNED_INT)
		return (if (!c->error) c->error = GL_INVALID_ENUM);
	if (sett->count < 0)
		return (if (!c->error) c->error = GL_INVALID_VALUE);
	if (!sett->count)
		return ;
	c->buffers.a[c->vertex_arrays.a[c->cur_vertex_array].element_buffer].type = \
		sett->type;
	settings = {mode, sett->offset, sett->count, 0, 0, GL_TRUE};
	run_pipeline(c, &settings);
}
