/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:40:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/30 10:49:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>
// #include <MLX42.h>
#include "tests.h"

int	run_test(t_gl_context *c, int test_num)
{
	printf("Testing %s...\n", g_tests[test_num].name);
	setup_context(c);
	g_tests[test_num].test_func(c, g_tests[test_num].num, NULL, NULL);
	mlx_loop(g_mlx_env.mlx);
}

int	run_tests(t_gl_context *c, int argc, char **argv)
{
	int	have_failure;
	int	i;
	int	found;

	have_failure = 0;
	if (argc == 1)
	{
		i = 0;
		while (i < NUM_TESTS)
		{
			have_failure |= run_test(c, i);
			printf("===== [%s] waiting 30 seconds =====\n",  g_tests[i].name);
			sleep(30);
			mlx_destroy_image(g_mlx_env.mlx, g_mlx_env.img);
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			found = find_test(argv[i]);
			if (found >= 0)
				have_failure |= run_test(c, found);
			else
				printf("Error: could not find test '%s'\n", argv[i]);
			i++;
		}
	}
	return (have_failure);
}

int	main(int argc, char **argv)
{
	t_gl_context	gl_context;
	int				fails;

	init_mlx();
	fails = run_tests(&gl_context, argc, argv);
	if (!fails)
		printf("All tests passed\n");
	return (fails);
}
