/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_set_xyzw_vec3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:46:10 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 12:20:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	setx_mat4v3(t_mat4 m, t_vec3 v)
{
	m[0][0] = v.x;
	m[0][1] = v.y;
	m[0][2] = v.z;
	m[0][3] = 0.0f;
}

void	sety_mat4v3(t_mat4 m, t_vec3 v)
{
	m[1][0] = v.x;
	m[1][1] = v.y;
	m[1][2] = v.z;
	m[1][3] = 0.0f;
}

void	setz_mat4v3(t_mat4 m, t_vec3 v)
{
	m[2][0] = v.x;
	m[2][1] = v.y;
	m[2][2] = v.z;
	m[2][3] = 0.0f;
}

void	setw_mat4v3(t_mat4 m, t_vec3 v)
{
	m[3][0] = v.x;
	m[3][1] = v.y;
	m[3][2] = v.z;
	m[3][3] = 1.0f;
}
