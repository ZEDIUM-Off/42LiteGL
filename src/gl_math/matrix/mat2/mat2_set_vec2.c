/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2_set_vec2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:34:48 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 16:48:44 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	setc1_mat2(t_mat2 m, vec2 v)
{
	m[0][0] = v.x;
	m[1][0] = v.x;
}

void	setc2_mat2(mat2 m, vec2 v)
{
	m[0][1] = v.x;
	m[1][1] = v.y;
}

void	setx_mat2(t_mat2 m, vec2 v)
{
	m[0][0] = v.x;
	m[0][1] = v.y;
}

void	sety_mat2(t_mat2 m, vec2 v)
{
	m[1][0] = v.x;
	m[1][1] = v.y;
}
