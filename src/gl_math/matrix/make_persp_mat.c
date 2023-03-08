/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_persp_mat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:26:45 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:37:15 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	make_perspective_matrix(
	t_mat4 mat, float fov, float aspect, float *near_far)
{
	float	t;
	float	b;
	float	l;
	float	r;

	t = near_far[0] * tanf(fov * 0.5f);
	b = -t;
	l = b * aspect;
	r = -l;
	make_perspective_proj_matrix(mat, {l, r}, {b, t}, near_far);
}

void	make_perspective_proj_matrix(
	t_mat4 mat, float *lr, float *bt, float *near_far)
{
	mat[0][0] = 2.0f * near_far[0] / (lr[1] - lr[0]);
	mat[0][1] = 0.0f;
	mat[0][2] = (lr[1] + lr[0]) / (lr[1] - lr[0]);
	mat[0][3] = 0.0f;
	mat[1][0] = 0.0f;
	mat[1][1] = 2.0f * near_far[0] / (bt[1] - bt[0]);
	mat[1][2] = (bt[1] + bt[0]) / (bt[1] - bt[0]);
	mat[1][3] = 0.0f;
	mat[2][0] = 0.0f;
	mat[2][1] = 0.0f;
	mat[2][2] = -((near_far[1] + near_far[0]) / (near_far[1] - near_far[0]));
	mat[2][3] = -((2.0f * near_far[1] * near_far[0])
			/ (near_far[1] - near_far[0]));
	mat[3][0] = 0.0f;
	mat[3][1] = 0.0f;
	mat[3][2] = -1.0f;
	mat[3][3] = 0.0f;
}

void	make_pers_matrix(t_mat4 mat, float z_near, float z_far)
{
	mat[0][0] = z_near;
	mat[0][1] = 0.0f;
	mat[0][2] = 0.0f;
	mat[0][3] = 0.0f;
	mat[1][0] = 0.0f;
	mat[1][1] = z_near;
	mat[1][2] = 0.0f;
	mat[1][3] = 0.0f;
	mat[2][0] = 0.0f;
	mat[2][1] = 0.0f;
	mat[2][2] = z_near + z_far;
	mat[2][3] = (z_near * z_far);
	mat[3][0] = 0.0f;
	mat[3][1] = 0.0f;
	mat[3][2] = -1.0f;
	mat[3][3] = 0.0f;
}
