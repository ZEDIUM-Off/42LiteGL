/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:43:11 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/30 11:11:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	clip_zmin(t_vec4 *c, t_vec4 *a, t_vec4 *b)
{
	float	t;
	float	den;

	den = -((b->z - a->z) + (b->w - a->w));
	if (den == 0)
		t = 0;
	else
		t = (-a->z - a->w) / den;
	c->x = a->x + t * (b->x - a->x);
	c->y = a->y + t * (b->y - a->y);
	c->w = a->w + t * (b->w - a->w);
	c->z = -c->w;
	return (t);
}

float	clip_zmax(t_vec4 *c, t_vec4 *a, t_vec4 *b)
{
	float	t;
	float	den;

	den = ((b->z - a->z) + (b->w - a->w));
	if (den == 0)
		t = 0;
	else
		t = (a->z - a->w) / den;
	c->x = a->x + t * (b->x - a->x);
	c->y = a->y + t * (b->y - a->y);
	c->w = a->w + t * (b->w - a->w);
	c->z = c->w;
	return (t);
}
