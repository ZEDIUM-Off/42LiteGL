/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_set_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:39:16 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 12:20:01 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	setc1_mat3(t_mat3 m, t_vec3 v)
{
	m[0][0] = v.x;
	m[1][0] = v.y;
	m[2][0] = v.z;
}

void	setc2_mat3(t_mat3 m, t_vec3 v)
{
	m[0][1] = v.x;
	m[1][1] = v.y;
	m[2][1] = v.z;
}

void	setc3_mat3(t_mat3 m, t_vec3 v)
{
	m[0][2] = v.x;
	m[1][2] = v.y;
	m[2][2] = v.z;
}
