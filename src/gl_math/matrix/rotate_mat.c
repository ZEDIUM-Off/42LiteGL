/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:48:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/04 12:43:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	rotate_mat4(t_mat4 m, t_gl_float angle, t_vec3 axis)
{
	t_gl_float	rad;
	t_gl_float	c;
	t_gl_float	s;
	t_mat4		rot;

	rad = radians(angle);
	c = cos(rad);
	s = sin(rad);
	identity_mat4(rot);
	rot[0][0] = c + axis.x * axis.x * (1 - c);
	rot[0][1] = axis.x * axis.y * (1 - c) - axis.z * s;
	rot[0][2] = axis.x * axis.z * (1 - c) + axis.y * s;
	rot[1][0] = axis.y * axis.x * (1 - c) + axis.z * s;
	rot[1][1] = c + axis.y * axis.y * (1 - c);
	rot[1][2] = axis.y * axis.z * (1 - c) - axis.x * s;
	rot[2][0] = axis.z * axis.x * (1 - c) - axis.y * s;
	rot[2][1] = axis.z * axis.y * (1 - c) + axis.x * s;
	rot[2][2] = c + axis.z * axis.z * (1 - c);
	mult_mat4_mat4(m, m, rot);
}
