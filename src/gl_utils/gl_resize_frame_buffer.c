/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_resize_frame_buffer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:03:49 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/25 14:26:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	*gl_resize_frame_buffer(t_gl_context *c, size_t w, size_t h)
{
	t_u8	*tmp;

	tmp = (t_u8 *)ft_realloc(c->zbuf.buf, w * h * sizeof(float),
			sizeof(float) * c->zbuf.w * c->zbuf.h);
	if (!tmp)
		return ((set_err(c, GL_OUT_OF_MEMORY)), NULL);
	c->zbuf.buf = tmp;
	c->zbuf.w = w;
	c->zbuf.h = h;
	c->zbuf.lastrow = c->zbuf.buf + (h - 1) * w * sizeof(float);
	tmp = (t_u8 *)ft_realloc(c->back_buffer.buf, w * h * sizeof(t_u32),
			sizeof(t_u32) * c->back_buffer.w * c->back_buffer.h);
	if (!tmp)
		return ((set_err(c, GL_OUT_OF_MEMORY)), NULL);
	c->back_buffer.buf = tmp;
	c->back_buffer.w = w;
	c->back_buffer.h = h;
	c->back_buffer.lastrow = c->back_buffer.buf + (h - 1) * w * sizeof(t_u32);
	return (tmp);
}
