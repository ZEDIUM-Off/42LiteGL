/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_mat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:57:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:58:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	translation_mat4(t_mat4 m, float x, float y, float z)
{
	m = identity_mat4();
	m[0][3] = x;
	m[1][3] = y;
	m[2][3] = z;
}
