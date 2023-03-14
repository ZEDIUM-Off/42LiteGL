/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:45:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 17:23:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

#define clip_func(name, sign, dir, dir1, dir2) \
static float name(t_vec4 *c, t_vec4 *a, t_vec4 *b) \
{\
	float t, dx, dy, dz, dw, den;\
	dx = (b->x - a->x);\
	dy = (b->y - a->y);\
	dz = (b->z - a->z);\
	dw = (b->w - a->w);\
	den = -(sign d ## dir) + dw;\
	if (den == 0) t=0;\
	else t = ( sign a->dir - a->w) / den;\
	c->dir1 = a->dir1 + t * d ## dir1;\
	c->dir2 = a->dir2 + t * d ## dir2;\
	c->w = a->w + t * dw;\
	c->dir = sign c->w;\
	return t;\
}

clip_func(clip_xmin, -, x, y, z);
clip_func(clip_xmax, +, x, y, z);
clip_func(clip_ymin, -, y, x, z);
clip_func(clip_ymax, +, y, x, z);
clip_func(clip_zmin, -, z, x, y);
clip_func(clip_zmax, +, z, x, y);

void	init_clip_proc(t_gl_context *c)
{
	c->clip_proc[0] = clip_zmin;
	c->clip_proc[1] = clip_zmax;
	c->clip_proc[2] = clip_xmin;
	c->clip_proc[3] = clip_xmax;
	c->clip_proc[4] = clip_ymin;
	c->clip_proc[5] = clip_ymax;
}