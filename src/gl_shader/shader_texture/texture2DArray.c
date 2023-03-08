/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2DArray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:03:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 15:44:42 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

typedef struct texture2d_vars
{
	int			i[2];
	int			j[2];
	t_glTexture	*t;
	t_Color		*color;
	double		alpha;
	double		beta;
	double		tmp;
	double		xw;
	double		yh;
	int			plane;
}	t_texture2d_vars;

void	set_vars(t_texture2d_vars *v, t_GLContext *c, t_gl_uint tex, t_vec3 xyz)
{
	v->t = &c->textures.a[tex];
	v->color = (t_Color *)v->t->data;
	v->xw = xyz.x * (v->t->w - EPSILON);
	v->yh = xyz.y * (v->t->h - EPSILON);
	v->plane = v->t->w * v->t->h;
	v->i[0] = warp(floor(v.xw), v->t->w, v->t->wrap_s);
	v->j[0] = warp(floor(v.yh), v->t->h, v->t->wrap_t);
	if (v.t->mag_filter != GL_NEAREST)
	{
		v->i[0] = warp(floor(v.xw - 0.5), v->t->w, v->t->wrap_s);
		v->i[1] = warp(floor(v.xw + 0.499999), v->t->w, v->t->wrap_s);
		v->j[0] = warp(floor(v.yh - 0.5), v->t->h, v->t->wrap_t);
		v->j[1] = warp(floor(v.yh + 0.499999), v->t->h, v->t->wrap_t);
		v->alpha = modf(v->xw + 0.5, &v->tmp);
		v->beta = modf(v->yh + 0.5, &v->tmp);
		if (v->alpha < 0)
			++v->alpha;
		if (v->beta < 0)
			++v->beta;
		v->alpha = v->alpha * v->alpha * (3 - 2 * v->alpha);
		v->beta = v->beta * v->beta * (3 - 2 * v->beta);
	}
}

t_vec4	texture2d_array(t_GLContext *c, t_gl_uint tex, t_vec3 xyz)
{
	t_texture2d_vars	v;

	set_vars(&v, c, tex, xy);
	if (v.t->mag_filter == GL_NEAREST)
		return (color_to_vec4(
				v.color[xyz.z * v.plane + v.j[0] * v.t->w + v.i[0]]));
	return (add_vec4s(add_vec4s(add_vec4s(
					scale_vec4(
						color_to_vec4(v.color[
								xyz.z * v.plane + v.j[0] * v.t->w + v.i[0]]),
						(1 - v->alpha) * (1 - v->beta)),
					scale_vec4(
						color_to_vec4(v.color[
								xyz.z * v.plane + v.j[0] * v.t->w + v.i[1]]),
						v->alpha * (1 - v->beta))),
				scale_vec4(color_to_vec4(v.color[
							xyz.z * v.plane + v.j[1] * v.t->w + v.i[0]]),
					(1 - v->alpha) * v->beta)),
			scale_vec4(color_to_vec4(v.color[
						xyz.z * v.plane + v.j[1] * v.t->w + v.i[1]]),
				v->alpha * v->beta)));
}
