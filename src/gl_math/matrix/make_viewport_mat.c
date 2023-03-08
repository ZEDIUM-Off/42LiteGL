/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_viewport_mat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:41:13 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:49:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	make_viewport_matrix(
	t_mat4 mat, float	*xy, unsigned int *wh, int opengl)
{
	float	lr[2];
	float	bt[2];

	lr[0] = xy[0] - 0.5f;
	bt[0] = xy[1] - 0.5f;
	lr[1] = lr[0] + wh[0];
	bt[1] = bt[0] + wh[1];
	if (opengl)
	{
		lr[0] = xy[0];
		bt[0] = xy[1];
		lr[1] = lr[0] + wh[0] - 0.01f;
		bt[1] = bt[0] + wh[1] - 0.01f;
	}
	mat = identity_mat4();
	mat[0][0] = (lr[1] - lr[0]) / 2.0f;
	mat[0][3] = (lr[1] + lr[0]) / 2.0f;
	mat[1][1] = (bt[1] - bt[0]) / 2.0f;
	mat[1][3] = (bt[1] + bt[0]) / 2.0f;
	mat[2][2] = 1.0f;
	mat[2][3] = 0.0f;
}
