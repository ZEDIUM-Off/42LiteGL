/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_negate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:57:10 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 10:58:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec2	negate_vec2(t_vec2 v)
{
	return (make_vec2(-v.x, -v.y));
}

t_vec3	negate_vec3(t_vec3 v)
{
	return (make_vec3(-v.x, -v.y, -v.z));
}

t_vec4	negate_vec4(t_vec4 v)
{
	return (make_vec4(-v.x, -v.y, -v.z, -v.w));
}
