/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:08:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 12:11:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_color	make_color(float r, float g, float b, float a)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

t_color	vec4_to_color(t_vec4 v)
{
	return (make_color(v.x * 255, v.y * 255, v.z * 255, v.w * 255));
}

t_vec4	color_to_vec4(t_color c)
{
	return (make_vec4((float)c.r / 255.0f, (float)c.g / 255.0f,
			(float)c.b / 255.0f, (float)c.a / 255.0f));
}
