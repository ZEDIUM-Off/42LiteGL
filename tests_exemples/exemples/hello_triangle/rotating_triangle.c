/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:24:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/04 13:39:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>
#include <stdio.h>
#include <SDL.h>
#define SDL_MAIN_HANDLED
#define WIDTH 800
#define HEIGHT 800

t_vec4 Red = { 1.0f, 0.0f, 0.0f, 0.0f };
t_vec4 Green = { 0.0f, 1.0f, 0.0f, 0.0f };
t_vec4 Blue = { 0.0f, 0.0f, 1.0f, 0.0f };

SDL_Window* window;
SDL_Renderer* ren;
SDL_Texture* tex;

t_u32* bbufpix;

typedef struct My_Uniforms
{
	t_mat4 mvp_mat;
	t_vec4 v_color;
} My_Uniforms;

void cleanup();
void setup_context();


void smooth_vs(float* vs_output, void* vertex_attribs, t_shader_builtins* builtins, void* uniforms);
void smooth_fs(float* fs_input, t_shader_builtins* builtins, void* uniforms);

int main(int argc, char** argv)
{
	t_gl_context	gl_context;

	setup_context(&gl_context);
	t_gl_enum smooth[4] = { SMOOTH, SMOOTH, SMOOTH, SMOOTH };

	float points[] = { -0.5, -0.5, 0,
	                    0.5, -0.5, 0,
	                    0,    0.5, 0 };

	float color_array[] = { 1.0, 0.0, 0.0, 1.0,
	                        0.0, 1.0, 0.0, 1.0,
	                        0.0, 0.0, 1.0, 1.0 };

	t_mat4 proj_mat, trans_mat, rot_mat, vp_mat;
	t_mat4 save_rot = identity_mat4();
	t_mat4 tmp_mat = identity_mat4();

	My_Uniforms the_uniforms;

	proj_mat = identity_mat4();
	make_perspective_matrix(proj_mat, radians(45), WIDTH/HEIGHT, new_float2(1, 20));
	trans_mat = identity_mat4();
	translation_mat4(trans_mat, 0, 0, -5);
	vp_mat = identity_mat4();
	mult_mat4_mat4(vp_mat, proj_mat, trans_mat);
	// printf("vp_mat:\n");
	// for (int i = 0; i < 4; i++)
	// {
	// 	for (int j = 0; j < 4; j++)
	// 		printf("%f ", vp_mat[i][j]);
	// 	printf("\n");
	// }
	// 	printf("\n");

	t_gl_uint triangle;
	gl_gen_buffers(&gl_context, 1, &triangle);
	gl_bind_buffer(&gl_context, GL_ARRAY_BUFFER, triangle);
	gl_buffer_data(&gl_context, GL_ARRAY_BUFFER, sizeof(t_gl_float)*9, points);
	gl_enable_vertex_attrib_array(&gl_context, 0);
	t_gl_vertex_attrib attr =  {.size = 3, .type = GL_FLOAT, .normalized = GL_FALSE, .stride = 0};
	gl_vertex_attrib_pointer(&gl_context, 0, attr, 0);
	t_gl_uint colors;
	gl_gen_buffers(&gl_context, 1, &colors);
	gl_bind_buffer(&gl_context, GL_ARRAY_BUFFER, colors);
	gl_buffer_data(&gl_context, GL_ARRAY_BUFFER, sizeof(float)*12, color_array);
	gl_enable_vertex_attrib_array(&gl_context, 4);
	t_gl_vertex_attrib attr2 =  {.size = 4, .type = GL_FLOAT, .normalized = GL_FALSE, .stride = 0};
	gl_vertex_attrib_pointer(&gl_context, 4, attr2, 0);
	t_gl_program prog_attr = {.vertex_shader = smooth_vs, .fragment_shader = smooth_fs, .vs_output_size = 4, .fragdepth_or_discard = GL_FALSE};
	t_gl_uint myshader = lgl_create_program(&gl_context, prog_attr, smooth);
	gl_use_program(&gl_context, myshader);
	lgl_set_uniform(&gl_context, &the_uniforms);
	the_uniforms.v_color = Red;
	gl_polygon_mode(&gl_context, GL_FRONT_AND_BACK, GL_POINT);
	gl_clear_color(&gl_context, new_float4(0, 0, 0, 1));
	printf("starting main loop ...");
	SDL_Event e;
	int quit = 0;

	unsigned int old_time = 0, new_time=0, counter = 0;
	unsigned int last_frame = 0;
	float frame_time = 0;

	rot_mat = identity_mat4();
	the_uniforms.mvp_mat = identity_mat4();
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = 1;
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				quit = 1;
			if (e.type == SDL_MOUSEBUTTONDOWN)
				quit = 1;
		}

		new_time = SDL_GetTicks();
		frame_time = (new_time - last_frame)/1000.0f;
		last_frame = new_time;
		counter++;
		if (!(counter % 300)) {
			printf("\n%d  %f ==================FPS\n", new_time-old_time, 300000/((float)(new_time-old_time)));
			old_time = new_time;
			counter = 0;
		}
		gl_clear(&gl_context, GL_COLOR_BUFFER_BIT);
		t_vec3 y_axis = { 0, 1, 0 };
		load_rotation_mat4(rot_mat, y_axis, radians(30) * frame_time);
		mult_mat4_mat4(tmp_mat, rot_mat, save_rot);
		mat4_cpy(save_rot, tmp_mat);
		mult_mat4_mat4(the_uniforms.mvp_mat, vp_mat, save_rot);
		
		gl_draw_arrays(&gl_context, GL_TRIANGLES, 0, 3);
		SDL_UpdateTexture(tex, NULL, bbufpix, WIDTH * sizeof(t_u32));
		SDL_RenderCopy(ren, tex, NULL, NULL);
		SDL_RenderPresent(ren);
	}
	cleanup(&gl_context);
	return 0;
}


void	smooth_vs(float *vs_output, void *vertex_attribs, t_shader_builtins *builtins, void *uniforms)
{
	t_vec4* v_attribs = vertex_attribs;
	((t_vec4*)vs_output)[0] = v_attribs[4]; //color

	builtins->gl_position = mult_mat4_vec4(*((t_mat4*)uniforms), v_attribs[0]);
}

void	smooth_fs(float *fs_input, t_shader_builtins *builtins, void *uniforms)
{
	builtins->gl_frag_color = ((t_vec4 *)fs_input)[0];
}

void setup_context(t_gl_context *c)
{
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("SDL_init error: %s\n", SDL_GetError());
		exit(0);
	}
	window = SDL_CreateWindow("rota_tri", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) {
		printf("Failed to create window\n");
		SDL_Quit();
		exit(0);
	}
	ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
	// t_context_settings settings = 
	if (!init_gl_context(c, (t_context_settings){&bbufpix, WIDTH, HEIGHT, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000})) {
		puts("Failed to initialize glContext");
		exit(0);
	}
}

void cleanup(t_gl_context *c)
{
	free_gl_context(c);
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
