/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture1D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:33:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 13:02:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

typedef struct texture1d_vars
{
	int			i[2];
	t_glTexture	*t;
	t_Color		*color;
	double		alpha;
	double		tmp;
}	t_texture1d_vars;

t_vec4	texture1d(t_GLContext *c, t_gl_uint tex, float x)
{
	t_texture1d_vars	v;

	v.t = &c->textures.a[tex];
	v.color = (t_Color *)v.t->data;
	if (v.t->mag_filter == GL_NEAREST)
	{
		v.i[0] = warp(floor(x * (v.t->w - EPSILON)), v.t->w, v.t->wrap_s);
		return (color_to_vec4(v.color[v.i[0]]));
	}
	v.i[0] = warp(floor(x * (v.t->w - EPSILON) - 0.5), v.t->w, v.t->wrap_s);
	v.i[1] = warp(ceil(x * (v.t->w - EPSILON) + 0.499999),
			v.t->w, v.t->wrap_s);
	v.alpha = modf(x * (v.t->w - EPSILON) + 0.5, &v.tmp);
	if (v.alpha < 0)
		++v.alpha;
	v.alpha = v.alpha * v.alpha * (3 - 2 * v.alpha);
	return (add_vec4s(
			scale_vec4(color_to_vec4(v.color[v.i[0]]), 1.0 - v.alpha),
			scale_vec4(color_to_vec4(v.color[v.i[1]]), v.alpha)));
}
