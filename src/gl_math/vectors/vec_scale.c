/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:05:39 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:05:56 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec2	scale_vec2s(t_vec2 v, float s)
{
	return (make_vec2(v.x * s, v.y * s));
}

t_vec3	scale_vec3s(t_vec3 v, float s)
{
	return (make_vec3(v.x * s, v.y * s, v.z * s));
}

t_vec4	scale_vec4s(t_vec4 v, float s)
{
	return (make_vec4(v.x * s, v.y * s, v.z * s, v.w * s));
}
