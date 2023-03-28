/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_cube_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:24:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/17 10:12:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>
#include <stdio.h>
#include <MLX42.h>

#define WIDTH 640
#define HEIGHT 480

t_vec4 Red = { 1.0f, 0.0f, 0.0f, 0.0f };
t_vec4 Green = { 0.0f, 1.0f, 0.0f, 0.0f };
t_vec4 Blue = { 0.0f, 0.0f, 1.0f, 0.0f };

typedef struct My_Uniforms
{
	t_mat4	mvp_mat;
	t_vec4	v_color;
}	My_Uniforms;

typedef struct s_mlx_env
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_mlx_env;

typedef struct s_global_context
{
	t_gl_context	*gl_context;
	t_mlx_env		*mlx_env;
	t_gl_uint	vao;
}	t_global_context;

t_u32* bbufpix;

void	cleanup();
void	setup_context();
void	smooth_vs(float* vs_output, void* vertex_attribs, t_shader_builtins* builtins, void* uniforms);
void	smooth_fs(float* fs_input, t_shader_builtins* builtins, void* uniforms);
void	update(void *gc);

int main(int argc, char** argv)
{
	t_gl_context		gl_context;
	t_mlx_env			mlx_env;
	t_global_context	global_context;

	setup_context(&gl_context, &mlx_env, &global_context);
	t_gl_enum smooth[4] = {SMOOTH, SMOOTH, SMOOTH, SMOOTH};

  float vertices[] = {
    // Front face
     0.5,  0.5,  0.5,
    -0.5,  0.5,  0.5,
    -0.5, -0.5,  0.5,
     0.5, -0.5,  0.5,

    // Back face
     0.5,  0.5, -0.5,
    -0.5,  0.5, -0.5,
    -0.5, -0.5, -0.5,
     0.5, -0.5, -0.5,
  };

  float vertex_colors[] = {
    1.0, 0.4, 0.6,
    1.0, 0.9, 0.2,
    0.7, 0.3, 0.8,
    0.5, 0.3, 1.0,

    0.2, 0.6, 1.0,
    0.6, 1.0, 0.4,
    0.6, 0.8, 0.8,
    0.4, 0.8, 0.8,
  };

  unsigned short triangle_indices[] = {
      // Front
      0, 1, 2,
      2, 3, 0,

      // Right
      0, 3, 7,
      7, 4, 0,

      // Bottom
      2, 6, 7,
      7, 3, 2,

      // Left
      1, 5, 6,
      6, 2, 1,

      // Back
      4, 7, 6,
      6, 5, 4,

      // Top
      5, 1, 0,
      0, 4, 5,
  };

	My_Uniforms the_uniforms;
	const t_gl_uint triangles = 6*2;
	const t_gl_uint vertices_index = 0;
	const t_gl_uint colors_index = 1;
	

	gl_enable(&gl_context, GL_DEPTH_TEST);

	gl_gen_vertex_arrays(&gl_context, 1, &global_context.vao);
	gl_bind_vertex_array(&gl_context, global_context.vao);
	
	t_gl_uint triangles_ebo;
	gl_gen_buffers(&gl_context, 1, &triangles_ebo);
	gl_bind_buffer(&gl_context, GL_ELEMENT_ARRAY_BUFFER, triangles_ebo);
	gl_buffer_data(&gl_context, GL_ELEMENT_ARRAY_BUFFER, sizeof(triangle_indices), triangle_indices);
	
	t_gl_uint verticies_vbo;
	gl_gen_buffers(&gl_context, 1, &verticies_vbo);
	gl_bind_buffer(&gl_context, GL_ARRAY_BUFFER, verticies_vbo);
	gl_buffer_data(&gl_context, GL_ARRAY_BUFFER, sizeof(vertices), vertices);
	
	t_gl_vertex_attrib attr =  {.size = 3, .type = GL_FLOAT, .normalized = GL_FALSE, .stride = 0};
	gl_vertex_attrib_pointer(&gl_context, vertices_index, attr, 0);
	gl_enable_vertex_attrib_array(&gl_context, vertices_index);
	
	t_gl_uint colors_vbo;
	gl_gen_buffers(&gl_context, 1, &colors_vbo);
	gl_bind_buffer(&gl_context, GL_ARRAY_BUFFER, colors_vbo);
	gl_buffer_data(&gl_context, GL_ARRAY_BUFFER, sizeof(vertex_colors), vertex_colors);
	
	t_gl_vertex_attrib attr2 =  {.size = 3, .type = GL_FLOAT, .normalized = GL_FALSE, .stride = 0};
	gl_vertex_attrib_pointer(&gl_context, colors_index, attr2, 0);
	gl_enable_vertex_attrib_array(&gl_context, colors_index);
	
	gl_bind_vertex_array(&gl_context, 0);
	gl_bind_buffer(&gl_context, GL_ELEMENT_ARRAY_BUFFER, 0);
	gl_bind_buffer(&gl_context, GL_ARRAY_BUFFER, 0);

	t_gl_program prog_attr = {.vertex_shader = smooth_vs, .fragment_shader = smooth_fs, .vs_output_size = 4, .fragdepth_or_discard = GL_FALSE};
	t_gl_uint myshader = lgl_create_program(&gl_context, prog_attr, smooth);
	gl_use_program(&gl_context, myshader);
	lgl_set_uniform(&gl_context, &the_uniforms);
	the_uniforms.v_color = Red;
	gl_clear_color(&gl_context, new_float4(0.1, 0.12, 0.2, 1));
	mlx_loop_hook(mlx_env.mlx, &update, &global_context);
	mlx_loop(mlx_env.mlx);
	cleanup(&gl_context);
	return (0);
}

void	update(void *gc)
{
	static t_mat4	save_rot;
	static t_mat4	vp_mat;
	t_mat4			tmp_mat;
	t_mat4			trans_mat;
	t_mat4			proj_mat;
	t_mat4			rot_mat;
	My_Uniforms *un;
	t_global_context *g_c;

	g_c = gc;
	if (!save_rot)
		save_rot = identity_mat4();
	if (!vp_mat)
	{
		proj_mat = identity_mat4();
		make_perspective_matrix(proj_mat, radians(45), 4 / 3, new_float2(1, 20));
		trans_mat = identity_mat4();
		translation_mat4(trans_mat, 0, 0, -5);
		vp_mat = identity_mat4();
		mult_mat4_mat4(vp_mat, proj_mat, trans_mat);
	}
	tmp_mat = identity_mat4();
	rot_mat = identity_mat4();
	un = g_c->gl_context->programs.a[g_c->gl_context->cur_program].uniform;
	un->mvp_mat = identity_mat4();
	load_rotation_mat4(rot_mat,
		(t_vec3){0, 1, 0}, radians(30) * 0.05);
	mult_mat4_mat4(tmp_mat, rot_mat, save_rot);
	mat4_cpy(save_rot, tmp_mat);
	mult_mat4_mat4(un->mvp_mat, vp_mat, save_rot);
	gl_clear(g_c->gl_context, GL_COLOR_BUFFER_BIT);
	gl_bind_vertex_array(g_c->gl_context, g_c->vao);
	t_draw_elements_settings draw_sett = {12 *3, GL_UNSIGNED_SHORT,NULL};
	gl_draw_elements(g_c->gl_context,GL_TRIANGLES, &draw_sett);
	if (mlx_is_key_down(g_c->mlx_env->mlx, MLX_KEY_ESCAPE))
		cleanup(g_c);
}

void	smooth_vs(float *vs_output, void *vertex_attribs, t_shader_builtins *builtins, void *uniforms)
{
	t_vec4* v_attribs = vertex_attribs;
	((t_vec4 *)vs_output)[0] = v_attribs[4]; //color
	builtins->gl_position = mult_mat4_vec4(*((t_mat4 *)uniforms), v_attribs[0]);
}

void	smooth_fs(float *fs_input, t_shader_builtins *builtins, void *uniforms)
{
	builtins->gl_frag_color = ((t_vec4 *)fs_input)[0];
}

void	setup_context(t_gl_context *c, t_mlx_env *mlx_env, t_global_context *gc)
{
	mlx_env->mlx = mlx_init(WIDTH, HEIGHT, "rota_tri_mlx", true);
	mlx_env->img = mlx_new_image(mlx_env->mlx, WIDTH, HEIGHT);
	if (!init_gl_context(c, (t_context_settings){(t_u32**)&mlx_env->img->pixels, WIDTH, HEIGHT, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000})) {
		puts("Failed to initialize glContext");
		exit(0);
	}
	mlx_image_to_window(mlx_env->mlx, mlx_env->img, 0, 0);
	gc->mlx_env = mlx_env;
	gc->gl_context = c;
}

void	cleanup(t_global_context *gc)
{
	mlx_delete_image(gc->mlx_env->mlx, gc->mlx_env->img);
	mlx_terminate(gc->mlx_env->mlx);
	mlx_close_window(gc->mlx_env->mlx);
	free_gl_context(gc->gl_context);
	printf("Exiting\n");
	exit(0);
}
