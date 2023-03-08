/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:08:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:09:40 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec2	vec4_to_vec2(t_vec4 v)
{
	return (make_vec2(v.x, v.y));
}

t_vec3	vec4_to_vec3(t_vec4 v)
{
	return (make_vec3(v.x, v.y, v.z));
}

t_vec2	vec4_to_vec2h(t_vec4 v)
{
	return (make_vec2(v.x / v.w, v.y / v.w));
}

t_vec3	vec4_to_vec3h(t_vec4 v)
{
	return (make_vec3(v.x / v.w, v.y / v.w, v.z / v.w));
}
