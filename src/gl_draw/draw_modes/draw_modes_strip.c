/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_modes_strip.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:45:41 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 15:01:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	line_strip_mode(t_GLContext *c, t_gl_int first, t_gl_sizei count)
{
	int	i;
	int	vert;

	i = first;
	vert = 0;
	while (i < first + count - 1)
	{
		draw_line_clip(c, &c->glverts.a[vert], &c->glverts.a[vert + 1]);
		i++;
		vert++;
	}
}

void	line_loop_mode(t_GLContext *c, t_gl_int first, t_gl_sizei count)
{
	int	i;
	int	vert;

	i = first;
	vert = 0;
	while (i < first + count - 1)
	{
		draw_line_clip(c, &c->glverts.a[vert], &c->glverts.a[vert + 1]);
		i++;
		vert++;
	}
	draw_line_clip(c, &c->glverts.a[count - 1], &c->glverts.a[0]);
}

void	triangle_strip_mode(t_GLContext *c, t_gl_sizei count)
{
	int	vert;
	int	provoke;
	int	a;
	int	b;
	int	toggle;

	vert = 2;
	a = 0;
	b = 1;
	provoke = -2;
	if (c->provoking_vert == GL_LAST_VERTEX_CONVENTION)
		provoke = 0;
	while (vert < count)
	{
		draw_triangle(c, {&c->glverts.a[a], &c->glverts.a[b],
			&c->glverts.a[vert]}, vert + provoke);
		if (!toggle)
			a = vert;
		else
			b = vert;
		toggle = !toggle;
		vert++;
	}
}

void	triangle_fan_mode(t_GLContext *c, t_gl_sizei count)
{
	int	vert;
	int	provoke;

	vert = 2;
	provoke = -1;
	if (c->provoking_vert == GL_LAST_VERTEX_CONVENTION)
		provoke = 0;
	while (vert < count)
	{
		draw_triangle(c, {&c->glverts.a[0], &c->glverts.a[vert - 1],
			&c->glverts.a[vert]}, vert + provoke);
		vert++;
	}
}
