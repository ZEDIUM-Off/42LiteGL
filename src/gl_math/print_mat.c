/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:31:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/22 11:34:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	print_mat4(t_mat4 mat, char *name)
{
	int	i;
	int	j;

	i = 0;
	printf("%s:\n", name);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f ", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_mat3(t_mat3 mat, char *name)
{
	int	i;
	int	j;

	i = 0;
	printf("%s:\n", name);
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			printf("%f ", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_mat2(t_mat2 mat, char *name)
{
	int	i;
	int	j;

	i = 0;
	printf("%s:\n", name);
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			printf("%f ", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
