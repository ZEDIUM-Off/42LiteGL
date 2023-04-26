/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_named_buffer_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:16:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/11 14:25:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_named_buffer_data(
	t_gl_context *c, t_gl_uint buffer, t_gl_sizei size, const t_gl_void *data)
{
	if (buffer == 0 || buffer >= c->buffers.size
		|| c->buffers.a[buffer].deleted)
		return ({if (!c->error) c->error = GL_INVALID_OPERATION;});
	free(c->buffers.a[buffer].data);
	c->buffers.a[buffer].data = (t_u8 *)malloc(size);
	if (!c->buffers.a[buffer].data)
		return ({if (!c->error) c->error = GL_OUT_OF_MEMORY;});
	if (data)
		ft_memcpy(c->buffers.a[buffer].data, data, size);
	c->buffers.a[buffer].user_owned = GL_FALSE;
	c->buffers.a[buffer].size = size;
	if (c->buffers.a[buffer].type == GL_ELEMENT_ARRAY_BUFFER - GL_ARRAY_BUFFER)
		c->vertex_arrays.a[c->cur_vertex_array].element_buffer = buffer;
}
