/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:43:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 22:11:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	in_loop(t_gl_context *c, t_gl_vertex **vert, unsigned int provoke)
{
	size_t	j;

	j = 0;
	while (j++ < c->vs_output.size)
	{
		if (c->vs_output.interpolation[j] != FLAT)
			fs_input[j] = vert[i]->vs_out[j];
		else
			fs_input[j] = c->vs_output.output_buf.a[
				provoke * c->vs_output.size + j];
	}
}

void	draw_triangle_point(
	t_gl_context *c, t_gl_vertex **vert, unsigned int provoke)
{
	float	fs_input[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	t_vec3	point;
	int		i;

	i = 0;
	while (i++ < 3)
	{
		if (!vert[i]->edge_flag)
			continue ;
		point = vec4_to_vec3h(vert[i]->screen_space);
		point.z = map(point.z, c->depth_range_near, c->depth_range_far);
		if (c->depth_clamp)
			point.z = clampf_01(point.z);
		in_loop(c, vert, provoke);
		c->builtins.discard = GL_FALSE;
		c->builtins.gl_FragDepth = point.z;
		c->programs.a[c->cur_program].fragment_shader(fs_input,
			&c->builtins, c->programs.a[c->cur_program].uniform);
		if (!c->builtins.discard)
			draw_pixel(c->builtins.gl_FragColor, point.x, point.y,
				c->builtins.gl_FragDepth);
	}
}
