/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:55:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 10:56:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec2	make_vec2(float x, float y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec3	make_vec3(float x, float y, float z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec4	make_vec4(float x, float y, float z, float w)
{
	t_vec4	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}
