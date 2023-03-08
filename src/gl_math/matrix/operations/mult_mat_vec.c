/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_mat_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:10:57 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 18:11:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec2	mult_mat2_vec2(t_mat2 m, t_vec2 v)
{
	return ((t_vec2){
		m[0][0] * v.x + m[0][1] * v.y,
		m[1][0] * v.x + m[1][1] * v.y});
}

t_vec3	mult_mat3_vec3(t_mat3 m, t_vec3 v)
{
	return ((t_vec3){
		m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z,
		m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z,
		m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z});
}

t_vec4	mult_mat4_vec4(t_mat4 m, t_vec4 v)
{
	return ((t_vec4){
		m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w,
		m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w,
		m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w,
		m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w});
}
