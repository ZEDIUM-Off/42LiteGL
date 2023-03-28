/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_interpolation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:36:18 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/23 12:01:51 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

typedef struct hi_uniforms
{
	t_mat4	mvp_mat;
	t_vec4	v_color;
}	t_hi_uniforms;

void	hi_smooth_vs(
	float *vs_output, void *vertex_attribs,
	t_shader_builtins *builtins, void *uniforms)
{
	t_vec4	*v_attribs;

	v_attribs = (t_vec4 *)vertex_attribs;
	((t_vec4 *)vs_output)[0] = v_attribs[4];
	*((t_mat4 *)uniforms) = identity_mat4();
	builtins->gl_position = mult_mat4_vec4(*((t_mat4 *)uniforms), v_attribs[0]);
}

void	hi_smooth_fs(
	float *fs_input, t_shader_builtins *builtins, void *uniforms)
{
	builtins->gl_frag_color = ((t_vec4 *)fs_input)[0];
}

void	set_itriangle(t_gl_context *c)
{
	float				points_n_colors[18] = {
		-0.5, -0.5, 0.0,
		1.0, 0.0, 0.0,

		0.5, -0.5, 0.0,
		0.0, 1.0, 0.0,

		0.0, 0.5, 0.0,
		0.0, 0.0, 1.0};
	t_gl_uint			triangle;
	t_gl_vertex_attrib	attr;

	gl_gen_buffers(c, 1, &triangle);
	gl_bind_buffer(c, GL_ARRAY_BUFFER, triangle);
	gl_buffer_data(c, GL_ARRAY_BUFFER,
		sizeof(points_n_colors), points_n_colors);
	gl_enable_vertex_attrib_array(c, 0);
	attr = (t_gl_vertex_attrib){.size = 3, .type = GL_FLOAT,
		.normalized = GL_FALSE, .stride = sizeof(float) * 6};
	gl_vertex_attrib_pointer(c, 0, attr, 0);
	gl_enable_vertex_attrib_array(c, 4);
	gl_vertex_attrib_pointer(c, 4, attr, (void *)(sizeof(float) * 3));
}

void	set_shader_and_uniforms(t_gl_context *c)
{
	t_gl_uint		shader;
	t_gl_program	prog_attr;
	t_hi_uniforms	uniforms;
	t_gl_enum		smooth[4] = {SMOOTH, SMOOTH, SMOOTH, SMOOTH};

	prog_attr = (t_gl_program){.vertex_shader = hi_smooth_vs, .fragment_shader
		= hi_smooth_fs, .vs_output_size = 4, .fragdepth_or_discard = GL_FALSE};
	shader = lgl_create_program(c, prog_attr, smooth);
	gl_use_program(c, shader);
	lgl_set_uniform(c, &uniforms);
	uniforms.mvp_mat = identity_mat4();
}

void	hello_interpolation(t_gl_context *c, int argc, char **argv, void *data)
{
	set_itriangle(c);
	set_shader_and_uniforms(c);
	gl_clear_color(c, new_float4(0.0f, 0.0f, 0.0f, 1.0f));
	gl_clear(c, GL_COLOR_BUFFER_BIT);
	gl_draw_arrays(c, GL_TRIANGLES, 0, 3);
}
