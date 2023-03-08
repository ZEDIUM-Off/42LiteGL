/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2_extract_vec2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:24:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 16:33:17 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec2	x_mat2(t_mat2 m)
{
	return (make_vec2(m[0][0], m[0][1]));
}

t_vec2	y_mat2(t_mat2 m)
{
	return (make_vec2(m[1][0], m[1][1]));
}

t_vec2	c1_mat2(mat2 m)
{
	return (make_vec2(m[0][0], m[1][0]));
}

t_vec2	c2_mat2(mat2 m)
{
	return (make_vec2(m[0][1], m[1][1]));
}
