/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_set_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:08:01 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 16:21:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	set_identity_mat2(t_mat2 mat)
{
	mat = identity_mat2();
}

void	set_identity_mat3(t_mat3 mat)
{
	mat = identity_mat3();
}

void	set_identity_mat4(t_mat4 mat)
{
	mat = identity_mat4();
}
