/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_get_xyzw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:42:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 16:43:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec4	x_mat4(t_mat4 m)
{
	return (make_vec4(m[0][0], m[0][1], m[0][2], m[0][3]));
}

t_vec4	y_mat4(t_mat4 m)
{
	return (make_vec4(m[1][0], m[1][1], m[1][2], m[1][3]));
}

t_vec4	z_mat4(t_mat4 m)
{
	return (make_vec4(m[2][0], m[2][1], m[2][2], m[2][3]));
}

t_vec4	w_mat4(t_mat4 m)
{
	return (make_vec4(m[3][0], m[3][1], m[3][2], m[3][3]));
}
