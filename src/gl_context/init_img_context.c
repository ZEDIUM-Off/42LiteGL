/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_context.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:48:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 15:20:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	alloc_zbuf(t_gl_context *c, t_context_settings *setts)
{
	c->zbuf.buf = (t_u8 *)malloc(setts->w * setts->h * sizeof(float));
	if (!c->zbuf.buf)
	{
		if (!c->user_alloced_backbuf)
		{
			free(*(setts->back));
			*(setts->back) = NULL;
		}
		return (0);
	}
	return (1);
}

int	alloc_sten_buf(t_gl_context *c, t_context_settings *setts)
{
	c->stencil_buf.buf = (t_u8 *)malloc(setts->w * setts->h);
	if (!c->stencil_buf.buf)
	{
		if (!c->user_alloced_backbuf)
		{
			free(*(setts->back));
			*setts->back = NULL;
		}
		return (0);
	}
	return (1);
}

//	init_mlx_context(c, setts);
int	init_img_context(t_gl_context *c, t_context_settings *setts)
{
	int	bpp;

	if (setts->bitdepth > 32 || !setts->back)
		return (0);
	c->user_alloced_backbuf = *(setts->back) != NULL;
	if (!*setts->back)
	{
		bpp = (setts->bitdepth + CHAR_BIT - 1) / CHAR_BIT;
		*setts->back = (t_u32 *)malloc(setts->w * setts->h * bpp);
		if (!*(setts->back))
			return (0);
	}
	if (!alloc_zbuf(c, setts))
		return (0);
	if (!alloc_sten_buf(c, setts))
		return (0);
	return (1);
}
