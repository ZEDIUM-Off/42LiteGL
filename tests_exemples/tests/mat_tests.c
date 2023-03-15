/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:00:38 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 13:22:09 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	main(void)
{
	t_mat4	m;

	make_perspective_matrix(m, 45.0f, 1, new_float2(0.1f, 100.0f));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%f ", m[i][j]);
		printf("\n");
	}
	return (0);
}
