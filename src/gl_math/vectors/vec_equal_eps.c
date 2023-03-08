/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_equal_eps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:07:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:07:52 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	equal_epsilon_vec2s(t_vec2 v1, t_vec2 v2, float eps)
{
	return (fabsf(v1.x - v2.x) < eps && fabsf(v1.y - v2.y) < eps);
}

int	equal_epsilon_vec3s(t_vec3 v1, t_vec3 v2, float eps)
{
	return (fabsf(v1.x - v2.x) < eps && fabsf(v1.y - v2.y) < eps
		&& fabsf(v1.z - v2.z) < eps);
}

int	equal_epsilon_vec4s(t_vec4 v1, t_vec4 v2, float eps)
{
	return (fabsf(v1.x - v2.x) < eps && fabsf(v1.y - v2.y) < eps
		&& fabsf(v1.z - v2.z) < eps && fabsf(v1.w - v2.w) < eps);
}
