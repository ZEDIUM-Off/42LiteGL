/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_bind_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:05:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 15:05:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_bind_buffer(t_GLContext *c, t_gl_enum target, t_gl_uint buffer)
{
	if (target != GL_ARRAY_BUFFER && target != GL_ELEMENT_ARRAY_BUFFER)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	target -= GL_ARRAY_BUFFER;
	if (buffer < c->buffers.size && c->buffers.a[buffer].deleted == GL_FALSE)
	{
		c->bound_buffers[target] = buffer;
		c->buffers.a[buffer].type = target;
	}
	else if (!c->error)
		c->error = GL_INVALID_OPERATION;
}
