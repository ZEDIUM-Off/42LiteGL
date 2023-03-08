/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:01:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:01:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec2	norm_vec2(t_vec2 v)
{
	float	lenght;

	lenght = vec2_lenght(v);
	return (make_vec2(v.x / lenght, v.y / lenght));
}

t_vec3	norm_vec3(t_vec3 v)
{
	float	lenght;

	lenght = vec3_lenght(v);
	return (make_vec3(v.x / lenght, v.y / lenght, v.z / lenght));
}

t_vec4	norm_vec4(t_vec4 v)
{
	float	lenght;

	lenght = vec4_lenght(v);
	return (make_vec4(v.x / lenght, v.y / lenght, v.z / lenght, v.w / lenght));
}
