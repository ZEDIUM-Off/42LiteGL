/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_clip_pt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:56:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 17:25:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

#define CLIP_EPSILON (1E-5)

int	gl_clipcode(t_gl_context *c, t_vec4 pt)
{
	float	w;

	w = pt.w * (1.0 + CLIP_EPSILON);
	return (
		(((pt.z < -w)
				| ((pt.z > w) << 1))
			& (!c->depth_clamp
				| !c->depth_clamp << 1))
		| ((pt.x < -w) << 2)
		| ((pt.x > w) << 3)
		| ((pt.y < -w) << 4)
		| ((pt.y > w) << 5));
}

void	update_clip_pt(
	t_gl_context *c, t_gl_vertex *q, t_gl_vertex **v, float t)
{
	int	i;

	i = 0;
	while (i < c->vs_output.size)
	{
		q->vs_out[i] = v[0]->vs_out[i]
			+ (v[1]->vs_out[i] - v[0]->vs_out[i]) * t;
		i++;
	}
	q->clip_code = gl_clipcode(c, q->clip_space);
}
