/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:57:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 17:57:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	mat4_cpy(t_mat4 dst, t_mat4 src)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			dst[i][j] = src[i][j];
		}
	}
}

void	mat3_cpy(t_mat3 dst, t_mat3 src)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			dst[i][j] = src[i][j];
		}
	}
}

void	mat2_cpy(t_mat2 dst, t_mat2 src)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			dst[i][j] = src[i][j];
		}
	}
}
