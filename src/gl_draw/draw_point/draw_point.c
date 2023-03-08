/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:11:41 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 10:58:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	draw_point_part(t_GLContext *c, int *ij, t_vec4 point, float *fs_input)
{
	float	origin;
	t_vec2	pos;

	origin = 1.0f;
	if (c->point_spr_origin == GL_UPPER_LEFT)
		origin = -1.0f;
	c->builtins.gl_PointCoord.x = 0.5f + ((int)ij[1] + 0.5f - point.x)
		/ c->point_size;
	c->builtins.gl_PointCoord.y = 0.5f + origin * ((int)ij[0] + 0.5f - point.y)
		/ c->point_size;
	set_vec4(c->builtins.gl_FragCoord, ij[1], ij[0], point.z, 1 / point.w);
	c->builtins.discard = GL_FALSE;
	c->builtins.gl_FragDepth = point.z;
	c->programs.a[c->cur_program].fragment_shader(fs_input, &c->builtins,
		c->programs.a[c->cur_program].uniform);
	if (!c->builtins.discard)
	{
		pos = {ij[1], ij[0]};
		draw_pixel(c, c->builtins.gl_FragColor, pos, c->builtins.gl_FragDepth);
	}
}

void	point_draw_loop(t_GLContext *c, float *xy,
		t_vec4 point, float *fs_input)
{
	int		i;
	int		j;

	i = xy[1] - c->point_size / 2;
	while (i < xy[1] + c->point_size / 2)
	{
		if (i < 0 || i >= c->back_buffer.h)
			continue ;
		j = xy[0] - c->point_size / 2;
		while (j < xy[0] - c->point_size / 2)
		{
			if (j < 0 || j >= c->back_buffer.w)
				continue ;
			draw_point_part(c, {i, j}, point, fs_input);
			j++;
		}
		i++;
	}
}

void	draw_point(t_GLContext *c, t_glVertex *vert)
{
	float	fs_input[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	t_vec4	point;
	float	x;
	float	y;

	point = vert->screen_space;
	printf("=============draw_point==============\npoint.w = %f \n", point.w);
	point.z = map(point.z, -1.0f, 1.0f,
			c->depth_range_near, c->depth_range_far);
	if (c->depth_clamp)
		point.z = clampf_01(point.z);
	ft_memcpy(fs_input, vert->vs_out, c->vs_outpout.size * sizeof(float));
	x = point.x + 0.5f;
	y = point.y + 0.5f;
	if (c->point_size <= 1)
		if (x < 0 || y < 0 || x >= c->back_buffer.w || y >= c->back_buffer.h)
			return ;
	point_draw_loop(c, {x, y}, point, fs_input);
}
