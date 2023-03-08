/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:06:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:06:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>	

int	equal_vec2s(t_vec2 v1, t_vec2 v2)
{
	return (v1.x == v2.x && v1.y == v2.y);
}

int	equal_vec3s(t_vec3 v1, t_vec3 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

int	equal_vec4s(t_vec4 v1, t_vec4 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w);
}
