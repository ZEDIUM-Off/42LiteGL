/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_modes_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:11 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 10:33:02 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	point_mode(t_GLContext *c, t_gl_uint first, t_gl_sizei count)
{
	int	i;
	int	vert;

	i = first;
	vert = 0;
	while (i < first + count)
	{
		c->glverts.a[vert].screen_space = mult_mat4_vec4(c->vp_mat,
				c->glverts.a[vert].clip_space);
		draw_point(c, &c->glverts.a[vert]);
		i++;
		vert++;
	}
}

void	line_mode(t_GLContext *c, t_gl_int first, t_gl_sizei count)
{
	int	i;
	int	vert;

	i = first;
	vert = 0;
	while (i < first + count - 1)
	{
		draw_line_clip(c, &c->glverts.a[vert], &c->glverts.a[vert + 1]);
		i += 2;
		vert += 2;
	}
}

void	triangle_mode(t_GLContext *c, t_gl_int first, t_gl_sizei count)
{
	int	i;
	int	vert;
	int	provoke;

	i = first;
	vert = 0;
	provoke = 0;
	if (c->provoking_vert == GL_LAST_VERTEX_CONVENTION)
		provoke = 2;
	while (i < first + count - 2)
	{
		draw_triangle(c, {&c->glverts.a[vert],
			&c->glverts.a[vert + 1], &c->glverts.a[vert + 2]}, vert + provoke);
		i += 3;
		vert += 3;
	}
}
