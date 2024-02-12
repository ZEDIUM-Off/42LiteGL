/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_cofactor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:33:39 by mchenava          #+#    #+#             */
/*   Updated: 2024/02/12 15:34:05 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	mat4_cofactor(t_mat4 res, t_mat4 mat)
{
	t_mat3	submat;
	int		i;
	int		j;
	int		k;
	int		l;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				l = -1;
				while (++l < 4)
				{
					if (k != i && l != j)
						submat[k - (k > i)][l - (l > j)] = mat[k][l];
				}
			}
			res[i][j] = mat3_determinant(submat);
		}
	}
}
