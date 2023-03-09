/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:31:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 14:43:39 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	clear_loop(t_GLContext *c, t_color col)
{
	int		i;
	int		x;
	int		y;

	if (!c->scissor_test)
	{
		i = 0;
		while (i < c->back_buffer.w * c->back_buffer.h)
			((u32 *)c->back_buffer.buf)[i++] = (u32)col.a << c->a_shift
				| (u32)col.r << c->r_shift
				| (u32)col.g << c->g_shift | (u32)col.b << c->b_shift;
	}
	else
	{
		y = c->scissor_ly;
		while (y < c->scissor_uy)
		{
			x = c->scissor_lx;
			while (x < c->scissor_ux)
				((u32 *)c->back_buffer.lastrow)[-y * c->back_buffer.w + x++]
					= (u32)col.a << c->a_shift | (u32)col.r << c->r_shift
					| (u32)col.g << c->g_shift | (u32)col.b << c->b_shift;
			y++;
		}
	}
}

void	gl_clear(t_GLContext *c, t_gl_bitfield mask)
{
	if (!(mask & (GL_COLOR_BUFFER_BIT
				| GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT)))
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	if (mask & GL_COLOR_BUFFER_BIT)
		clear_loop(c, c->clear_color);
}
