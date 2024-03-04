/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_det.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:28:40 by mchenava          #+#    #+#             */
/*   Updated: 2024/02/14 17:32:26 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	mat4_determinant(t_mat4 mat)
{
	float	det = 0;
	float	submat[3][3];
	int		i, j, m, n;

	for (int c = 0; c < 4; c++)
	{
		m = 0;
		for (i = 1; i < 4; i++)
		{
			n = 0;
			for (j = 0; j < 4; j++)
			{
				if (j != c)
				{
					submat[m][n] = mat[i][j];
					n++;
				}
			}
			m++;
		}
		float s = (c % 2 == 0) ? 1 : -1;
		det += s * mat[0][c] * mat3_determinant(submat);
	}
	return det;
}

float	mat3_determinant(t_mat3 mat)
{
	return (mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
		- mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
		+ mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]));
}
