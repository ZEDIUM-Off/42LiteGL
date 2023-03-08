/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:59:45 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:00:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	normalize_vec2(t_vec2 *v)
{
	float	lenght;

	lenght = vec2_lenght(*v);
	v->x /= lenght;
	v->y /= lenght;
}

void	normalize_vec3(t_vec3 *v)
{
	float	lenght;

	lenght = vec3_lenght(*v);
	v->x /= lenght;
	v->y /= lenght;
	v->z /= lenght;
}

void	normalize_vec4(t_vec4 *v)
{
	float	lenght;

	lenght = vec4_lenght(*v);
	v->x /= lenght;
	v->y /= lenght;
	v->z /= lenght;
	v->w /= lenght;
}
