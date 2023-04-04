/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:45:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/30 17:38:51 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <lite_gl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <mlx_int.h>
# include <unistd.h>

# define WIDTH 640
# define HEIGHT 640

# define NUM_TESTS 4

typedef struct litegl_test
{
	char	name[50];
	void	(*test_func)(t_gl_context*, int, char**, void*);
	int		num;
}	t_litegl_test;

typedef struct s_mlx_env
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_img		*img;
	/*char		*img_addr;
	int			bpp;
	int			line_len;
	int			endian;*/
}	t_mlx_env;

t_mlx_env		g_mlx_env;

void	hello_triangle(t_gl_context *c, int argc, char **argv, void *data);
void	hello_cube(t_gl_context *c, int argc, char **argv, void *data);
void	hello_indexing(t_gl_context *c, int argc, char **argv, void *data);
void	hello_interpolation(t_gl_context *c, int argc, char **argv, void *data);

t_litegl_test	g_tests[NUM_TESTS] = {
	(t_litegl_test){"hello_triangle", hello_triangle},
	(t_litegl_test){"hello_cube", hello_cube},
	(t_litegl_test){"hello_indexing", hello_indexing},
	(t_litegl_test){"hello_interpolation", hello_interpolation},
};

int	find_test(char *name)
{
	int	i;

	i = 0;
	while (i < NUM_TESTS)
		if (!strcmp(name, g_tests[i++].name))
			return (i - 1);
	return (-1);
}

void	init_mlx(void)
{
	g_mlx_env.mlx = mlx_init();
	g_mlx_env.mlx->use_xshm = 1;
	g_mlx_env.win = mlx_new_window(g_mlx_env.mlx,
			WIDTH, HEIGHT, "42LiteGL - tests");
	if (!g_mlx_env.mlx)
	{
		puts("Failed to initialize mlx");
		exit(0);
	}
	printf("mlx initialized\n");
}

void	free_mlx(void)
{
	mlx_destroy_window(g_mlx_env.mlx, g_mlx_env.win);
	mlx_destroy_display(g_mlx_env.mlx);
	free(g_mlx_env.mlx);
}

// t_u32	*img_buffer;

// void	my_mlx_put_image_to_window(t_mlx_env *mlx_env, t_u32 *img, int x, int y)
// {

// 	mlx_put_image_to_window(mlx_env->mlx, mlx_env->win, mlx_env->img, x, y);
// }

void	setup_context(t_gl_context *c)
{
	g_mlx_env.img = mlx_new_image(g_mlx_env.mlx, WIDTH, HEIGHT);
	g_mlx_env.img->type = MLX_TYPE_XIMAGE;
	if (!init_gl_context(c, (t_context_settings){
			(t_u32 **)&g_mlx_env.img->data, WIDTH, HEIGHT, 32,
			0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000}))
	{
		puts("Failed to initialize glContext");
		exit(0);
	}
	mlx_put_image_to_window(g_mlx_env.mlx, g_mlx_env.win, g_mlx_env.img, 0, 0);
	printf("Context initialized\n");
}

#endif