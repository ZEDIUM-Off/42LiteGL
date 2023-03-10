/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_named_buffer_sub_data.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:20:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 15:23:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_named_buffer_sub_data(
	t_GLContext *c, t_gl_uint buffer,
	t_gl_sizei offset_size, const t_gl_void *data)
{
	if (buffer == 0 || buffer >= c->buffers.size
		|| c->buffers.a[buffer].deleted)
		return (if (!c->error) c->error = GL_INVALID_OPERATION);
	if (offset_size[0] + offset_size[1] > c->buffers.a[buffer].size)
		return (if (!c->error) c->error = GL_INVALID_VALUE);
	ft_memcpy(&c->buffers.a[buffer].data[offset_size[0]], data, offset_size[1]);
}
