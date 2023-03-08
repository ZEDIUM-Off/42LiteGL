/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:53:38 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 10:55:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	set_vec2(t_vec2 *v, float x, float y)
{
	v->x = x;
	v->y = y;
}

void	set_vec3(t_vec3 *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void	set_vec4(t_vec4 *v, float *coords)
{
	v->x = coords[0];
	v->y = coords[1];
	v->z = coords[2];
	v->w = coords[3];
}
