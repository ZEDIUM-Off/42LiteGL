/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:24:46 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/03 11:30:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec3	vec3_rotate(t_vec3 base_vec, float angle, t_vec3 rot_arround)
{
	t_vec3	result;
	float	s;
	float	c;

	s = sinf(angle);
	c = cosf(angle);
	result = (t_vec3){
		rot_arround.x * (rot_arround.x * base_vec.x + rot_arround.y
			* base_vec.y + rot_arround.z * base_vec.z)
		* (1.0f - c) + base_vec.x
		* c - (-rot_arround.z * base_vec.y + rot_arround.y * base_vec.z) * s,
		rot_arround.y * (rot_arround.x * base_vec.x + rot_arround.y
			* base_vec.y + rot_arround.z * base_vec.z)
		* (1.0f - c) + base_vec.y
		* c - (rot_arround.z * base_vec.x - rot_arround.x * base_vec.z) * s,
		rot_arround.z * (rot_arround.x * base_vec.x + rot_arround.y
			* base_vec.y + rot_arround.z * base_vec.z)
		* (1.0f - c) + base_vec.z
		* c - (-rot_arround.y * base_vec.x + rot_arround.x * base_vec.y) * s
	};
	(void)base_vec;
	(void)rot_arround;
	return (result);
}
