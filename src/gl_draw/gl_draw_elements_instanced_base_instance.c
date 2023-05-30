/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw_elements_instanced_base_instance.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:05:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/25 14:21:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_draw_elements_instanced_base_instance(
	t_gl_context *c, t_gl_enum mode, t_draw_elements_instanced_settings *sett)
{
	t_gl_sizei			i;
	t_pipeline_settings	settings;

	if (mode < GL_POINTS || mode > GL_TRIANGLE_FAN)
		return (set_err(c, GL_INVALID_ENUM));
	if (sett->type != GL_UNSIGNED_BYTE && sett->type != GL_UNSIGNED_SHORT
		&& sett->type != GL_UNSIGNED_INT)
		return (set_err(c, GL_INVALID_ENUM));
	if (sett->count < 0 || sett->instancecount < 0)
		return (set_err(c, GL_INVALID_ENUM));
	if (!sett->count || !sett->instancecount)
		return ;
	c->buffers.a[c->vertex_arrays.a[c->cur_vertex_array].element_buffer].type = \
	sett->type;
	i = 0;
	while (i < sett->instancecount)
	{
		settings = (t_pipeline_settings){mode, sett->offset, sett->count,
			i, sett->baseinstance, GL_TRUE};
		run_pipeline(c, &settings);
		i++;
	}
}
