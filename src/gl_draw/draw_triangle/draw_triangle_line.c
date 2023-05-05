/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:53:10 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/05 15:51:47 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	draw_triangle_line(
	t_gl_context *c, t_gl_vertex **v, unsigned int provoke)
{
	if (v[0]->edge_flag)
		draw_line_shader(c,
			(t_vec4 [2]){v[0]->screen_space, v[1]->screen_space},
			(float *[2]){v[0]->vs_out, v[1]->vs_out}, provoke);
	if (v[1]->edge_flag)
		draw_line_shader(c,
			(t_vec4 [2]){v[1]->screen_space, v[2]->screen_space},
			(float *[2]){v[1]->vs_out, v[2]->vs_out}, provoke);
	if (v[2]->edge_flag)
		draw_line_shader(c,
			(t_vec4 [2]){v[2]->screen_space, v[0]->screen_space},
			(float *[2]){v[2]->vs_out, v[0]->vs_out}, provoke);
}
