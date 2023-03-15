/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:21:54 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 15:31:51 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>
#include <SDL.h>
#define SDL_MAIN_HANDLED
#define WIDTH 640
#define HEIGHT 480

SDL_Window* window;
SDL_Renderer* ren;
SDL_Texture* tex;

t_u32* bbufpix;

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


t_u32* bbufpix;

int	main(void)
{
	t_gl_context	gl_context;

	setup_context(&gl_context);

	SDL_Event e;
	int quit = 0;

	unsigned int old_time = 0, new_time=0, counter = 0;
	unsigned int last_frame = 0;
	float frame_time = 0;
		
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
		gl_clear_color(&gl_context, new_float4(0, 0, 0, 1));
		gl_clear(&gl_context, GL_COLOR_BUFFER_BIT);
		SDL_UpdateTexture(tex, NULL, bbufpix, WIDTH * sizeof(t_u32));
		SDL_RenderCopy(ren, tex, NULL, NULL);
		SDL_RenderPresent(ren);
	}
	cleanup(&gl_context);
	return (0);
}
