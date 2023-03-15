/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_mat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:47:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 13:19:59 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_mat2	identity_mat2(void)
{
	t_mat2	mat;

	mat = (float **)malloc(sizeof(float *) * 2);
	mat[0] = (float *)malloc(sizeof(float) * 2);
	mat[1] = (float *)malloc(sizeof(float) * 2);
	mat[0][0] = 1.0f;
	mat[0][1] = 0.0f;
	mat[1][0] = 0.0f;
	mat[1][1] = 1.0f;
	return (mat);
}

t_mat3	identity_mat3(void)
{
	t_mat3	mat;

	mat = (float **)malloc(sizeof(float *) * 3);
	mat[0] = (float *)malloc(sizeof(float) * 3);
	mat[1] = (float *)malloc(sizeof(float) * 3);
	mat[2] = (float *)malloc(sizeof(float) * 3);
	mat[0][0] = 1.0f;
	mat[0][1] = 0.0f;
	mat[0][2] = 0.0f;
	mat[1][0] = 0.0f;
	mat[1][1] = 1.0f;
	mat[1][2] = 0.0f;
	mat[2][0] = 0.0f;
	mat[2][1] = 0.0f;
	mat[2][2] = 1.0f;
	return (mat);
}

t_mat4	identity_mat4(void)
{
	t_mat4	mat;

	mat = (float **)malloc(sizeof(float *) * 4);
	mat[0] = (float *)malloc(sizeof(float) * 4);
	mat[1] = (float *)malloc(sizeof(float) * 4);
	mat[2] = (float *)malloc(sizeof(float) * 4);
	mat[3] = (float *)malloc(sizeof(float) * 4);
	mat[0][0] = 1.0f;
	mat[0][1] = 0.0f;
	mat[0][2] = 0.0f;
	mat[0][3] = 0.0f;
	mat[1][0] = 0.0f;
	mat[1][1] = 1.0f;
	mat[1][2] = 0.0f;
	mat[1][3] = 0.0f;
	mat[2][0] = 0.0f;
	mat[2][1] = 0.0f;
	mat[2][2] = 1.0f;
	mat[2][3] = 0.0f;
	mat[3][0] = 0.0f;
	mat[3][1] = 0.0f;
	mat[3][2] = 0.0f;
	mat[3][3] = 1.0f;
	return (mat);
}
