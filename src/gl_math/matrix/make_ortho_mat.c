/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ortho_mat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:38:07 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:40:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	make_orthographic_matrix(
	t_mat4 mat, float	*lr, float *bt, float *near_far)
{
	mat[0][0] = 2.0f / (lr[1] - lr[0]);
	mat[0][1] = 0.0f;
	mat[0][2] = 0.0f;
	mat[0][3] = -((lr[1] + lr[0]) / (lr[1] - lr[0]));
	mat[1][0] = 0.0f;
	mat[1][1] = 2.0f / (bt[1] - bt[0]);
	mat[1][2] = 0.0f;
	mat[1][3] = -((bt[1] + bt[0]) / (bt[1] - bt[0]));
	mat[2][0] = 0.0f;
	mat[2][1] = 0.0f;
	mat[2][2] = 2.0f / (near_far[1] - near_far[0]);
	mat[2][3] = -((near_far[1] + near_far[0]) / (near_far[1] - near_far[0]));
	mat[3][0] = 0.0f;
	mat[3][1] = 0.0f;
	mat[3][2] = 0.0f;
	mat[3][3] = 1.0f;
}
