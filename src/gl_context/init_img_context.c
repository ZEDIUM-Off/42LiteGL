/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_context.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:48:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/08 11:54:59 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	alloc_zbuf(t_GLContext *c, t_context_settings *setts)
{
	c->zbuf.buf = (u8 *)malloc(setts->w * setts->h * sizeof(float));
	if (!c->zbuf.buf)
	{
		if (!c->user_alloced_backbuf)
		{
			free(*(setts->back))
			*(setts->back) = NULL;
		}
		return (0);
	}
	return (1);
}

int	alloc_sten_buf(t_GLContext *c, t_context_settings *setts)
{
	c->stencil_buf.buf = (u8 *)malloc(setts->w * setts->h);
	if (!c->stencil_buf.buf)
	{
		if (!c->user_alloced_backbuf)
		{
			free(*(setts->back))
			*(setts->back) = NULL;
		}
		return (0);
	}
	return (1);
}

int	init_img_context(t_GLContext *c, t_context_settings *setts)
{
	int	bpp;

	init_mlx_context(c, setts);
	if (setts->bitdepth > 32 || !setts->back)
		return (0);
	c->user_alloced_backbuff = *(setts->back) != NULL;
	if (!*(setts->back))
	{
		bpp = (setts->bitdepth + CHAR_BIT - 1) / CHAR_BIT;
		*(setts->back) = (u32 *)malloc(setts->w * setts->h * bpp);
		if (!*(setts->back))
			return (0);
	}
	if (!alloc_zbuf(c, setts))
		return (0);
	if (!alloc_sten_buf(c, setts))
		return (0);
	return (1);
}
