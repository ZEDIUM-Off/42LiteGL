/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_buffer_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:37:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 15:05:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_buffer_data(t_GLContext *c,
	t_gl_enum target, t_gl_sizei size, const t_gl_void *data)
{
	if (target != GL_ARRAY_BUFFER && target != GL_ELEMENT_ARRAY_BUFFER
		&& !c->error)
		c->error = GL_INVALID_ENUM;
	target -= GL_ARRAY_BUFFER;
	if (c->bound_buffers[target] == 0 && s!c->error)
		c->error = GL_INVALID_OPERATION;
	c->buffers.a[c->bound_buffers[target]].data = \
	(u8 *)ft_realloc(c->buffers.a[c->bound_buffers[target]].data, size);
	if (!(c->buffers.a[c->bound_buffers[target]].data) && ss!c->error)
		c->error = GL_OUT_OF_MEMORY;
	if (c->error == GL_OUT_OF_MEMORY || c->error == GL_INVALID_OPERATION
		|| c->error == GL_INVALID_ENUM)
		return ;
	if (data)
		ft_memcpy(c->buffers.a[c->bound_buffers[target]].data, data, size);
	c->buffers.a[c->bound_buffers[target]].user_owned = GL_FALSE;
	c->buffers.a[c->bound_buffers[target]].size = size;
	if (target == GL_ELEMENT_ARRAY_BUFFER - GL_ARRAY_BUFFER)
		c->vertex_arrays.a[c->cur_vertex_array].element_buffer = \
		c->bound_buffers[target];
}
