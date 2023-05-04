/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:55:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/04 12:42:43 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	scale_mat3(t_mat3 m, float x, float y, float z)
{
	identity_mat3(m);
	m[0][0] = x;
	m[1][1] = y;
	m[2][2] = z;
}

void	scale_mat4(t_mat4 m, float x, float y, float z)
{
	identity_mat4(m);
	m[0][0] = x;
	m[1][1] = y;
	m[2][2] = z;
}
