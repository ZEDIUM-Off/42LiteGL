/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_cubemap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:26:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 16:07:58 by  mchenava        ###   ########.fr       */
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
	int			p;
	float		mag[3];
	float		s;
	float		t1;
	float		max;
}	t_texture2d_vars;

void	x_mag_larger_y(t_texture2d_vars *v, t_vec3 *xyz)
{
	if (v->mag[0] > v->mag[2])
	{
		v->max = v->mag[0];
		v->t1 = -xyz->y;
		v->p = 1;
		v->s = xyz->z;
		if (v->mag[0] == xyz->x)
		{
			v->p = 0;
			v->s = -xyz->z;
		}
	}
	else
	{
		v->max = v->mag[2];
		v->t1 = -xyz->y;
		v->p = 5;
		v->s = -xyz->x;
		if (v->mag[2] == xyz->z)
		{
			v->p = 4;
			v->s = xyz->x;
		}
	}
}

void	y_mag_larger_x(t_texture2d_vars *v, t_vec3 *xyz)
{
	if (v->mag[1] > v->mag[2])
	{
		v->max = v->mag[1];
		v->s = xyz->x;
		v->p = 3;
		v->t1 = -xyz->z;
		if (v->mag[1] == xyz->y)
		{
			v->p = 2;
			v->t1 = xyz->z;
		}
	}
	else
	{
		v->max = v->mag[2];
		v->t1 = -xyz->y;
		v->p = 5;
		v->s = -xyz->x;
		if (v->mag[2] == xyz->z)
		{
			v->p = 4;
			v->s = xyz->x;
		}
	}
}

void	set_xyz(t_texture2d_vars *v, t_vec3 *xyz)
{
	if (xyz->x < 0)
		v->mag[0] = -xyz->x;
	if (xyz->y < 0)
		v->mag[1] = -xyz->y;
	if (xyz->z < 0)
		v->mag[2] = -xyz->z;
	if (v->mag[0] > v->mag[1])
		x_mag_larger_y(v, xyz);
	else
		y_mag_larger_x(v, xyz);
	xyz->x = (v->s / v->max + 1.0f) / 2.0f;
	xyz->y = (v->t1 / v->max + 1.0f) / 2.0f;
}

void	set_vars(t_texture2d_vars *v, t_GLContext *c, t_gl_uint tex, t_vec3 xyz)
{
	v->t = &c->textures.a[tex];
	v->color = (t_Color *)v->t->data;
	set_xyz(v, &xyz);
	v->xw = xyz.x * (v->t->w - EPSILON);
	v->yh = xyz.y * (v->t->h - EPSILON);
	v->plane = v->t->w * v->t->w;
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

t_vec4	texture_cubemap(t_GLContext *c, t_gl_uint tex, t_vec3 xyz)
{
	t_texture2d_vars	v;

	set_vars(&v, c, tex, xyz);
	if (v.t->mag_filter == GL_NEAREST)
		return (color_to_vec4(
				v.color[v.p * v.plane + v.j[0] * v.t->w + v.i[0]]));
	return (add_vec4s(add_vec4s(add_vec4s(
					scale_vec4(
						color_to_vec4(v.color[
								v.p * v.plane + v.j[0] * v.t->w + v.i[0]]),
						(1 - v->alpha) * (1 - v->beta)),
					scale_vec4(
						color_to_vec4(v.color[
								v.p * v.plane + v.j[0] * v.t->w + v.i[1]]),
						v->alpha * (1 - v->beta))),
				scale_vec4(color_to_vec4(v.color[
							v.p * v.plane + v.j[1] * v.t->w + v.i[0]]),
					(1 - v->alpha) * v->beta)),
			scale_vec4(color_to_vec4(v.color[
						v.p * v.plane + v.j[1] * v.t->w + v.i[1]]),
				v->alpha * v->beta)));
}
