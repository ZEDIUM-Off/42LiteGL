/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_indexing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:20:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/05 13:28:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	set_buffers(t_gl_context *c)
{
	float				points[12] = {
		-0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
	};
	unsigned int		indices[6] = {
		0, 1, 2,
		2, 1, 3
	};
	t_gl_uint			square;
	t_gl_uint			elements;
	t_gl_vertex_attrib	attr;

	gl_gen_buffers(c, 1, &square);
	gl_bind_buffer(c, GL_ARRAY_BUFFER, square);
	gl_buffer_data(c, GL_ARRAY_BUFFER, sizeof(points), points);
	gl_gen_buffers(c, 1, &elements);
	gl_bind_buffer(c, GL_ELEMENT_ARRAY_BUFFER, elements);
	gl_buffer_data(c, GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices);
	gl_enable_vertex_attrib_array(c, 0);
	attr = (t_gl_vertex_attrib){.size = 3, .type = GL_FLOAT,
		.normalized = GL_FALSE, .stride = 0};
	gl_vertex_attrib_pointer(c, 0, attr, 0);
}

void	hello_indexing(t_gl_context *c, int argc, char **argv, void *data)
{
	t_draw_elements_settings	sett;

	set_buffers(c);
	gl_clear_color(c, new_float4(0.0f, 0.0f, 0.0f, 1.0f));
	gl_clear(c, GL_COLOR_BUFFER_BIT);
	sett = (t_draw_elements_settings){6, GL_UNSIGNED_INT, 0};
	gl_draw_elements(c, GL_TRIANGLES, &sett);
}
