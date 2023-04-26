/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_buffer_sub_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:06:11 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/11 14:25:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_buffer_sub_data(
	t_gl_context *c, t_gl_enum target,
	t_gl_sizei *offset_size, const t_gl_void *data)
{
	if (target != GL_ARRAY_BUFFER && target != GL_ELEMENT_ARRAY_BUFFER)
		return ({if (!c->error) c->error = GL_INVALID_ENUM;});
	target -= GL_ARRAY_BUFFER;
	if (c->bound_buffers[target] == 0)
		return ({if (!c->error) c->error = GL_INVALID_OPERATION;});
	if (offset_size[0] + offset_size[1]
		> c->buffers.a[c->bound_buffers[target]].size)
		return ({if (!c->error) c->error = GL_INVALID_VALUE;});
	ft_memcpy(&c->buffers.a[c->bound_buffers[target]].data[offset_size[0]],
		data, offset_size[1]);
}
