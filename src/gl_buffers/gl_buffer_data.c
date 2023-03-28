/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_buffer_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:37:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/21 16:57:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_buffer_data(t_gl_context *c,
	t_gl_enum target, t_gl_sizei size, const t_gl_void *data)
{
	if (target != GL_ARRAY_BUFFER && target != GL_ELEMENT_ARRAY_BUFFER)
		return ({if (!c->error) c->error = GL_INVALID_ENUM;});
	target -= GL_ARRAY_BUFFER;
	if (c->bound_buffers[target] == 0)
		return ({if (!c->error) c->error = GL_INVALID_OPERATION;});
	c->buffers.a[c->bound_buffers[target]].data = \
	ft_realloc(c->buffers.a[c->bound_buffers[target]].data, size);
	if (!(c->buffers.a[c->bound_buffers[target]].data))
		return ({if (!c->error) c->error = GL_OUT_OF_MEMORY;});
	if (data)
		ft_memcpy(c->buffers.a[c->bound_buffers[target]].data, data, size);
	c->buffers.a[c->bound_buffers[target]].user_owned = GL_FALSE;
	c->buffers.a[c->bound_buffers[target]].size = size;
	printf("gl_buffer_data, c->vertex_arrays.a[c->cur_vertex_array].element_buffer = %d\n",c->vertex_arrays.a[c->cur_vertex_array].element_buffer);
	if (target == GL_ELEMENT_ARRAY_BUFFER - GL_ARRAY_BUFFER)
		c->vertex_arrays.a[c->cur_vertex_array].element_buffer = \
		c->bound_buffers[target];
}
