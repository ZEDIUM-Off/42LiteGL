/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_resize_frame_buffer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:03:49 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/08 14:08:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	*gl_resize_frame_buffer(t_GLContext *c, size_t w, size_t h)
{
	u8	*tmp;

	tmp = (u8 *)ft_realloc(c->zbuf.buf, w * h * sizeof(float));
	if (!tmp)
	{
		if (!c->error)
			c->error = GL_OUT_OF_MEMORY;
		return (NULL);
	}
	c->zbuf.buf = tmp;
	c->zbuf.w = w;
	c->zbuf.h = h;
	c->zbuf.lastrow = c->zbuf.buf + (h - 1) * w * sizeof(float);
	tmp = (u8 *)realloc(c->back_buffer.buf, w * h * sizeof(u32));
	if (!tmp)
	{
		if (!c->error)
			c->error = GL_OUT_OF_MEMORY;
		return (NULL);
	}
	c->back_buffer.buf = tmp;
	c->back_buffer.w = w;
	c->back_buffer.h = h;
	c->back_buffer.lastrow = c->back_buffer.buf + (h - 1) * w * sizeof(u32);
	return (tmp);
}
