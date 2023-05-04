/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:11:41 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/04 12:50:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	draw_point_part(t_gl_context *c, int *ij, t_vec4 point, float *fs_input)
{
	float	origin;
	t_vec2	pos;

	origin = 1.0f;
	if (c->point_spr_origin == GL_UPPER_LEFT)
		origin = -1.0f;
	c->builtins.gl_point_coord.x = 0.5f + ((int)ij[1] + 0.5f - point.x)
		/ c->point_size;
	c->builtins.gl_point_coord.y = 0.5f + origin * ((int)ij[0] + 0.5f - point.y)
		/ c->point_size;
	set_vec4(&c->builtins.gl_frag_coord,
		(float [4]){ij[1], ij[0], point.z, 1 / point.w});
	c->builtins.discard = GL_FALSE;
	c->builtins.gl_frag_depth = point.z;
	c->programs.a[c->cur_program].fragment_shader(fs_input, &c->builtins,
		c->programs.a[c->cur_program].uniform);
	if (!c->builtins.discard)
	{
		pos = (t_vec2){ij[1], ij[0]};
		draw_pixel(c, c->builtins.gl_frag_color,
			pos, c->builtins.gl_frag_depth);
	}
}

void	point_draw_loop(t_gl_context *c, float *xy,
		t_vec4 point, float *fs_input)
{
	float	i;
	float	j;

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
			draw_point_part(c, (int [2]){i, j}, point, fs_input);
			j++;
		}
		i++;
	}
}

void	draw_point(t_gl_context *c, t_gl_vertex *vert)
{
	float	fs_input[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	t_vec4	point;
	float	x;
	float	y;

	point = vert->screen_space;
	point.z = map(point.z, c->depth_range_near, c->depth_range_far);
	if (c->depth_clamp)
		point.z = clampf_01(point.z);
	ft_memcpy(fs_input, vert->vs_out, c->vs_output.size * sizeof(float));
	x = point.x + 0.5f;
	y = point.y + 0.5f;
	if (c->point_size <= 1)
		if (x < 0 || y < 0 || x >= c->back_buffer.w || y >= c->back_buffer.h)
			return ;
	point_draw_loop(c, (float [2]){x, y}, point, fs_input);
}
