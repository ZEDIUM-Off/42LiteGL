/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:47:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/28 10:28:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_float	vertices[] = {
	-1, -1, -1,
	1, -1, -1,
	1, 1, -1,
	-1, 1, -1,
	-1, -1, 1,
	1, -1, 1,
	1, 1, 1,
	-1, 1, 1
};

t_gl_float	colors[] = {
	0, 0, 0,
	1, 0, 0,
	1, 1, 0,
	0, 1, 0,
	0, 0, 1,
	1, 0, 1,
	1, 1, 1,
	0, 1, 1
};

t_gl_float	cube_indices[] = {
	0, 3, 2, 1,
	2, 3, 7, 6,
	0, 4, 7, 3,
	1, 2, 6, 5,
	4, 5, 6, 7,
	0, 1, 5, 4
};

void	smooth_vs(
	float *vs_output, void *vertex_attribs,
	t_shader_builtins *builtins, void *uniforms)
{
	t_vec4	*v_attribs = vertex_attribs;

	((t_vec4 *)vs_output)[0] = v_attribs[4];
	*((t_mat4 *)uniforms) = identity_mat4();
	builtins->gl_position = mult_mat4_vec4(*((t_mat4 *)uniforms), v_attribs[0]);
}

void	smooth_fs(float *fs_input, t_shader_builtins *builtins, void *uniforms)
{
	builtins->gl_frag_color = ((t_vec4 *)fs_input)[0];
}

void	display(t_gl_context *c)
{
	t_draw_elements_settings	settings;

	gl_clear(c, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	settings = (t_draw_elements_settings){24, GL_UNSIGNED_BYTE, cube_indices};
	gl_draw_elements(c, GL_TRIANGLES, &settings);
}

void	create_cube(t_gl_context *c)
{
	t_gl_uint	vao;
	t_gl_uint	vbo;
	t_gl_uint	ibo;

	gl_gen_vertex_arrays(c, 1, &vao);
	gl_bind_vertex_array(c, vao);
	gl_gen_buffers(c, 1, &vbo);
	gl_bind_buffer(c, GL_ARRAY_BUFFER, vbo);
	gl_buffer_data(c, GL_ARRAY_BUFFER, sizeof(vertices), vertices);
	t_gl_vertex_attrib attr = (t_gl_vertex_attrib){3, GL_FLOAT, GL_FALSE, 0};
	gl_vertex_attrib_pointer(c, 0, attr, 0);
	gl_enable_vertex_attrib_array(c, 0);
	gl_gen_buffers(c, 1, &ibo);
	gl_bind_buffer(c, GL_ELEMENT_ARRAY_BUFFER, ibo);
	gl_buffer_data(c, GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indices), cube_indices);
	gl_bind_buffer(c, GL_ARRAY_BUFFER, 0);
	gl_bind_vertex_array(c, 0);
}

void	hello_cube(t_gl_context *c, int argc, char **argv, void *data)
{
	t_gl_uint	shader;
	t_gl_enum smooth[4] = { SMOOTH, SMOOTH, SMOOTH, SMOOTH };


	(void)argc;
	(void)argv;
	(void)data;
	gl_enable(c, GL_DEPTH_TEST);
	gl_depth_func(c, GL_LESS);
	t_gl_program prog_attr = (t_gl_program){.vertex_shader = smooth_vs, .fragment_shader
		= smooth_fs, .vs_output_size = 4, .fragdepth_or_discard = GL_FALSE};
	shader = lgl_create_program(c, prog_attr, smooth);
	gl_use_program(c, shader);
	create_cube(c);
	display(c);
}
