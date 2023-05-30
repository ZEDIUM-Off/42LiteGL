/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:02:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/30 11:03:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	clip_xmin(t_vec4 *c, t_vec4 *a, t_vec4 *b)
{
	float	t;
	float	den;

	den = -((b->x - a->x) + (b->w - a->w));
	if (den == 0)
		t = 0;
	else
		t = (-a->x - a->w) / den;
	c->y = a->y + t * (b->y - a->y);
	c->z = a->z + t * (b->z - a->z);
	c->w = a->w + t * (b->w - a->w);
	c->x = -c->w;
	return (t);
}

float	clip_xmax(t_vec4 *c, t_vec4 *a, t_vec4 *b)
{
	float	t;
	float	den;

	den = (b->x - a->x) + (b->w - a->w);
	if (den == 0)
		t = 0;
	else
		t = (a->x - a->w) / den;
	c->y = a->y + t * (b->y - a->y);
	c->z = a->z + t * (b->z - a->z);
	c->w = a->w + t * (b->w - a->w);
	c->x = c->w;
	return (t);
}
