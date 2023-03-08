/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:03:46 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:04:07 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec2	mult_vec2s(t_vec2 v1, t_vec2 v2)
{
	return (make_vec2(v1.x * v2.x, v1.y * v2.y));
}

t_vec3	mult_vec3s(t_vec3 v1, t_vec3 v2)
{
	return (make_vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}

t_vec4	mult_vec4s(t_vec4 v1, t_vec4 v2)
{
	return (make_vec4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w));
}
