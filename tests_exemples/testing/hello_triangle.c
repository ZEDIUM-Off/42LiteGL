/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:14:00 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/30 16:49:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

typedef struct ht_uniforms
{
	t_mat4	mvp_mat;
	t_vec4	v_color;
}	t_ht_uniforms;

void	ht_normal_vs(
	float *vs_output, void *vertex_attribs,
	t_shader_builtins *builtins, void *uniforms)
{
	*(t_mat4 *)uniforms = identity_mat4();
	builtins->gl_position = mult_mat4_vec4(*((t_mat4 *)uniforms),
			((t_vec4 *)vertex_attribs)[0]);
}

void	ht_normal_fs(float *fs_input,
	t_shader_builtins *builtins, void *uniforms)
{
	builtins->gl_frag_color = ((t_ht_uniforms *)uniforms)->v_color;
}

void	set_triangle(t_gl_context *c)
{
	float				points[9] = {
		-0.5, -0.5, 0,
		0.5, -0.5, 0,
		0, 0.5, 0};
	t_gl_uint			triangle;
	t_gl_vertex_attrib	attr;

	gl_gen_buffers(c, 1, &triangle);
	gl_bind_buffer(c, GL_ARRAY_BUFFER, triangle);
	gl_buffer_data(c, GL_ARRAY_BUFFER, sizeof(points), points);
	gl_enable_vertex_attrib_array(c, 0);
	attr = (t_gl_vertex_attrib){.size = 3, .type = GL_FLOAT,
		.normalized = GL_FALSE, .stride = 0};
	gl_vertex_attrib_pointer(c, 0, attr, 0);
}

void	set_shader_and_uniform(t_gl_context	*c)
{
	t_gl_uint		myshader;
	t_gl_program	prog_attr;
	t_ht_uniforms	uniforms;

	prog_attr = (t_gl_program){.vertex_shader = ht_normal_vs, .fragment_shader
		= ht_normal_fs, .vs_output_size = 0, .fragdepth_or_discard = GL_FALSE};
	myshader = lgl_create_program(c, prog_attr, NULL);
	gl_use_program(c, myshader);
	lgl_set_uniform(c, &uniforms);
	uniforms.v_color = (t_vec4){1.0, 0.0, 1.0, 0.0};
	uniforms.mvp_mat = identity_mat4();
}

void	hello_triangle(t_gl_context *c, int argc, char **argv, void *data)
{
	printf("Hello Triangle\n");
	set_triangle(c);
	set_shader_and_uniform(c);
	gl_polygon_mode(c, GL_FRONT_AND_BACK, GL_LINE);
	gl_clear_color(c, new_float4(0.0f, 0.0f, 1.0f, 1.0f));
	gl_clear(c, GL_COLOR_BUFFER_BIT);
	gl_draw_arrays(c, GL_TRIANGLES, 0, 3);
}
