/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:59:18 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 12:01:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	clamp(float value, float min, float max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

float	clamp_01(float value)
{
	return (clamp(value, 0.0f, 1.0f));
}

t_vec2	clamp_vec2(t_vec2 v, float min, float max)
{
	return (make_vec2(clamp(v.x, min, max), clamp(v.y, min, max)));
}

t_vec3	clamp_vec3(t_vec3 v, float min, float max)
{
	return (make_vec3(clamp(v.x, min, max),
			clamp(v.y, min, max), clamp(v.z, min, max)));
}

t_vec4	clamp_vec4(t_vec4 v, float min, float max)
{
	return (make_vec4(clamp(v.x, min, max),
			clamp(v.y, min, max), clamp(v.z, min, max), clamp(v.w, min, max)));
}
