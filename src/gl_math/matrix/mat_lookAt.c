/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_lookAt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:50:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 11:54:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	look_at(t_mat4 mat, t_vec3 eye, t_vec3 center, t_vec3 up)
{
	t_vec3	f;
	t_vec3	s;
	t_vec3	u;

	set_identity_mat4(mat);
	f = norm_vec3(sub_vec3s(center, eye));
	s = norm_vec3(cross_product(f, up));
	u = cross_product(s, f);
	setx_mat4v3(mat, s);
	sety_mat4v3(mat, u);
	setz_mat4v3(mat, negate_vec3(f));
	setc4_mat4v3(mat, make_vec3(-dot_vec3s(s, eye),
			-dot_vec3s(u, eye), dot_vec3s(f, eye)));
}
