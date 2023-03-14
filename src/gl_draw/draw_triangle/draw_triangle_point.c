/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:43:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 12:46:39 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	in_loop(t_gl_context *c, t_gl_vertex *vert, unsigned int provoke,
	float **fs_input)
{
	int	j;

	j = 0;
	while (j++ < c->vs_output.size)
	{
		if (c->vs_output.interpolation[j] != FLAT)
			*fs_input[j] = vert->vs_out[j];
		else
			*fs_input[j] = c->vs_output.output_buf.a[
				provoke * c->vs_output.size + j];
	}
}

void	draw_triangle_point(
	t_gl_context *c, t_gl_vertex **vert, unsigned int provoke)
{
	float	*fs_input;
	t_vec3	point;
	int		i;

	i = 0;
	fs_input = (float *)malloc(sizeof(float) * GL_MAX_VERTEX_OUTPUT_COMPONENTS);
	while (i++ < 3)
	{
		if (!vert[i]->edge_flag)
			continue ;
		point = vec4_to_vec3h(vert[i]->screen_space);
		point.z = map(point.z, c->depth_range_near, c->depth_range_far);
		if (c->depth_clamp)
			point.z = clampf_01(point.z);
		in_loop(c, vert[i], provoke, &fs_input);
		c->builtins.discard = GL_FALSE;
		c->builtins.gl_frag_depth = point.z;
		c->programs.a[c->cur_program].fragment_shader(fs_input,
			&c->builtins, c->programs.a[c->cur_program].uniform);
		if (!c->builtins.discard)
			draw_pixel(c, c->builtins.gl_frag_color, (t_vec2){point.x, point.y},
				c->builtins.gl_frag_depth);
	}
}
