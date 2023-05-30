/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:04:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/30 11:08:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	clip_ymin(t_vec4 *c, t_vec4 *a, t_vec4 *b)
{
	float	t;
	float	den;

	den = -((b->y - a->y) + (b->w - a->w));
	if (den == 0)
		t = 0;
	else
		t = (-a->y - a->w) / den;
	c->x = a->x + t * (b->x - a->x);
	c->z = a->z + t * (b->z - a->z);
	c->w = a->w + t * (b->w - a->w);
	c->y = -c->w;
	return (t);
}

float	clip_ymax(t_vec4 *c, t_vec4 *a, t_vec4 *b)
{
	float	t;
	float	den;

	den = ((b->y - a->y) + (b->w - a->w));
	if (den == 0)
		t = 0;
	else
		t = (a->y - a->w) / den;
	c->x = a->x + t * (b->x - a->x);
	c->z = a->z + t * (b->z - a->z);
	c->w = a->w + t * (b->w - a->w);
	c->y = c->w;
	return (t);
}
