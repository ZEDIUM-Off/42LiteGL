/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:41:23 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 15:02:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

typedef struct texture3d_vars
{
	int			i[2];
	int			j[2];
	int			k[2];
	t_glTexture	*t;
	t_Color		*color;
	double		alpha;
	double		beta;
	double		gamma;
	double		tmp;
	double		xw;
	double		yh;
	double		zd;
	int			plane;
}	t_texture3d_vars;

void	set_vars_mag_not_nearest(t_texture3d_vars *v)
{
	v->i[0] = warp(floor(v->xw - 0.5), v->t->w, v->t->wrap_s);
	v->j[0] = warp(floor(v->yh - 0.5), v->t->h, v->t->wrap_t);
	v->k[0] = warp(floor(v->zd - 0.5), v->t->d, v->t->wrap_r);
	v->i[1] = warp(ceil(v->xw + 0.499999), v->t->w, v->t->wrap_s);
	v->j[1] = warp(ceil(v->yh + 0.499999), v->t->h, v->t->wrap_t);
	v->k[1] = warp(ceil(v->zd + 0.499999), v->t->d, v->t->wrap_r);
	v->alpha = modf(v->xw + 0.5, &v->tmp);
	v->beta = modf(v->yh + 0.5, &v->tmp);
	v->gamma = modf(v->zd + 0.5, &v->tmp);
	if (v->alpha < 0)
		++v->alpha;
	if (v->beta < 0)
		++v->beta;
	if (v->gamma < 0)
		++v->gamma;
	v->alpha = v->alpha * v->alpha * (3 - 2 * v->alpha);
	v->beta = v->beta * v->beta * (3 - 2 * v->beta);
	v->gamma = v->gamma * v->gamma * (3 - 2 * v->gamma);
}

void	set_vars(t_texture3d_vars *v, t_GLContext *c, t_gl_uint tex, t_vec3 xyz)
{
	v->t = &c->textures.a[tex];
	v->color = (t_Color *)v->t->data;
	v->xw = xyz.x * (v->t->w - EPSILON);
	v->yh = xyz.y * (v->t->h - EPSILON);
	v->zd = xyz.z * (v->t->d - EPSILON);
	v->plane = v->t->w * v->t->h;
	v->i[0] = warp(floor(v->xw), v->t->w, v->t->wrap_s);
	v->j[0] = warp(floor(v->yh), v->t->h, v->t->wrap_t);
	v->k[0] = warp(floor(v->zd), v->t->d, v->t->wrap_r);
	if (v.t->mag_filter != GL_NEAREST)
		set_vars_mag_not_nearest(v);
}

t_color	find_color(t_texture3d_vars *v, int i, int j, int k)
{
	return (v->color[k * v->plane + j * v->t->w + i]);
}

void	set_colors(t_vec4 **c, t_texture3d_vars *v)
{
	(*c)[0] = scale_vec4(color_to_vec4(find_color(
					v, v->i[0], v->j[0], v->k[0])),
			(1 - alpha) * (1 - beta) * (1 - gamma));
	(*c)[1] = scale_vec4(color_to_vec4(find_color(
					v, v->i[1], v->j[0], v->k[0])),
			alpha * (1 - beta) * (1 - gamma));
	(*c)[2] = scale_vec4(color_to_vec4(find_color(
					v, v->i[0], v->j[1], v->k[0])),
			(1 - alpha) * beta * (1 - gamma));
	(*c)[3] = scale_vec4(color_to_vec4(find_color(
					v, v->i[1], v->j[1], v->k[0])), alpha * beta * (1 - gamma));
	(*c)[4] = scale_vec4(color_to_vec4(find_color(
					v, v->i[0], v->j[0], v->k[1])),
			(1 - alpha) * (1 - beta) * gamma);
	(*c)[5] = scale_vec4(color_to_vec4(find_color(
					v, v->i[1], v->j[0], v->k[1])), alpha * (1 - beta) * gamma);
	(*c)[6] = scale_vec4(color_to_vec4(find_color(
					v, v->i[0], v->j[1], v->k[1])), (1 - alpha) * beta * gamma);
	(*c)[7] = scale_vec4(color_to_vec4(find_color(
					v, v->i[1], v->j[1], v->k[1])), alpha * beta * gamma);
}

t_vec4	texture3d(t_GLContext *c, t_gl_uint tex, t_vec3 xyz)
{
	t_texture3d_vars	v;
	t_vec4				colors[8];

	set_vars(&v, c, tex, xyz);
	if (v.t->mag_filter == GL_NEAREST)
		return (color_to_vec4(find_color(&v, v.i[0], v.j[0], v.k[0])));
	set_colors(&colors, &v);
	colors[0] = add_vec4s(colors[0], colors[1]);
	colors[0] = add_vec4s(colors[0], colors[2]);
	colors[0] = add_vec4s(colors[0], colors[3]);
	colors[0] = add_vec4s(colors[0], colors[4]);
	colors[0] = add_vec4s(colors[0], colors[5]);
	colors[0] = add_vec4s(colors[0], colors[6]);
	colors[0] = add_vec4s(colors[0], colors[7]);
	return (colors[0]);
}
