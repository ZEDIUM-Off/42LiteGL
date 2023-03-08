/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rot_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:14:24 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:22:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	load_rotation_mat2(t_mat2 mat, float angle)
{
	mat[0][0] = cos(angle);
	mat[0][1] = -sin(angle);
	mat[1][0] = sin(angle);
	mat[1][1] = cos(angle);
}

void	load_rotation_mat3(t_mat3 mat, t_vec3 v, float angle)
{
	normalize_vec3(&v);
	mat[0][0] = ((1 - cos(angle)) * v.x * v.x) + cos(angle);
	mat[0][1] = ((1 - cos(angle)) * v.x * v.y) - (sin(angle) * v.z);
	mat[0][2] = ((1 - cos(angle)) * v.x * v.z) + (sin(angle) * v.y);
	mat[1][0] = ((1 - cos(angle)) * v.y * v.x) + (sin(angle) * v.z);
	mat[1][1] = ((1 - cos(angle)) * v.y * v.y) + cos(angle);
	mat[1][2] = ((1 - cos(angle)) * v.y * v.z) - (sin(angle) * v.x);
	mat[2][0] = ((1 - cos(angle)) * v.z * v.x) - (sin(angle) * v.y);
	mat[2][1] = ((1 - cos(angle)) * v.z * v.y) + (sin(angle) * v.x);
	mat[2][2] = ((1 - cos(angle)) * v.z * v.z) + cos(angle);
}

void	load_rotation_mat4(t_mat4 mat, t_vec3 v, float angle)
{
	normalize_vec3(&v);
	mat[0][0] = ((1 - cos(angle)) * v.x * v.x) + cos(angle);
	mat[0][1] = ((1 - cos(angle)) * v.x * v.y) - (sin(angle) * v.z);
	mat[0][2] = ((1 - cos(angle)) * v.x * v.z) + (sin(angle) * v.y);
	mat[0][3] = 0;
	mat[1][0] = ((1 - cos(angle)) * v.y * v.x) + (sin(angle) * v.z);
	mat[1][1] = ((1 - cos(angle)) * v.y * v.y) + cos(angle);
	mat[1][2] = ((1 - cos(angle)) * v.y * v.z) - (sin(angle) * v.x);
	mat[1][3] = 0;
	mat[2][0] = ((1 - cos(angle)) * v.z * v.x) - (sin(angle) * v.y);
	mat[2][1] = ((1 - cos(angle)) * v.z * v.y) + (sin(angle) * v.x);
	mat[2][2] = ((1 - cos(angle)) * v.z * v.z) + cos(angle);
	mat[2][3] = 0;
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
}
