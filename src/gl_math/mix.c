/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:04:40 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 12:05:57 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	mix(float x, float y, float a)
{
	return (x * (1.0 - a) + y * a);
}

t_vec2	mix_vec2(t_vec2 x, t_vec2 y, float a)
{
	return (add_vec2s(scale_vec2s(x, 1.0 - a), scale_vec2s(y, a)));
}

t_vec3	mix_vec3(t_vec3 x, t_vec3 y, float a)
{
	return (add_vec3s(scale_vec3s(x, 1.0 - a), scale_vec3s(y, a)));
}

t_vec4	mix_vec4(t_vec4 x, t_vec4 y, float a)
{
	return (add_vec4s(scale_vec4s(x, 1.0 - a), scale_vec4s(y, a)));
}
