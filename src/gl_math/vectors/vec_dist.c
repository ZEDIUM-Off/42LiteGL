/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:02:01 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 11:53:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	distance_vec2(t_vec2 v1, t_vec2 v2)
{
	return (length_vec2(sub_vec2s(v1, v2)));
}

float	distance_vec3(t_vec3 v1, t_vec3 v2)
{
	return (length_vec3(sub_vec3s(v1, v2)));
}
