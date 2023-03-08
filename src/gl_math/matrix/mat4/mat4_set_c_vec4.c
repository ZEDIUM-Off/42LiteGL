/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_set_c_vec4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:45:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 16:45:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	setc1_mat4v4(t_mat4 m, t_vec4 v)
{
	m[0][0] = v.x;
	m[1][0] = v.y;
	m[2][0] = v.z;
	m[3][0] = v.w;
}

void	setc2_mat4v4(t_mat4 m, t_vec4 v)
{
	m[0][1] = v.x;
	m[1][1] = v.y;
	m[2][1] = v.z;
	m[3][1] = v.w;
}

void	setc3_mat4v4(t_mat4 m, t_vec4 v)
{
	m[0][2] = v.x;
	m[1][2] = v.y;
	m[2][2] = v.z;
	m[3][2] = v.w;
}

void	setc4_mat4v4(t_mat4 m, t_vec4 v)
{
	m[0][3] = v.x;
	m[1][3] = v.y;
	m[2][3] = v.z;
	m[3][3] = v.w;
}
