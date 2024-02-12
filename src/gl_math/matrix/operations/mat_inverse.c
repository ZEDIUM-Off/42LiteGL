/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_inverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:03:03 by mchenava          #+#    #+#             */
/*   Updated: 2024/02/12 15:36:31 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	mat4_inverse(t_mat4	res, t_mat4 mat)
{
	float	det;
	t_mat4	adj;
	t_mat4	cofactor;
	int		i;
	int		j;

	det = mat4_determinant(mat);
	if (det == 0)
	{
		printf("Determinant is 0, matrix is not invertible\n");
		return ;
	}
	mat4_cofactor(cofactor, mat);
	mat4_transpose(adj, cofactor);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			res[i][j] = adj[i][j] / det;
	}
}
