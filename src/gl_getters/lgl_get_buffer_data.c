/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_get_buffer_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:26:38 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 14:30:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	lgl_get_buffer_data(
	t_gl_context *c, t_gl_uint buffer, t_gl_void **data)
{
	if (!data)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	if (buffer && buffer < c->buffers.size && !c->buffers.a[buffer].deleted)
		*data = c->buffers.a[buffer].data;
	else if (!c->error)
		c->error = GL_INVALID_OPERATION;
}
