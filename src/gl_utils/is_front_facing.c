/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_front_facing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:13:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 17:25:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	is_front_facing(t_gl_context *c,
	t_gl_vertex *v0, t_gl_vertex *v1, t_gl_vertex *v2)
{
	t_vec3	normal;
	t_vec3	tmpvec3;

	tmpvec3 = (t_vec3){0, 0, 1};
	normal = cross_product(sub_vec3s(vec4_to_vec3h(v1->screen_space),
				vec4_to_vec3h(v0->screen_space)), sub_vec3s(
				vec4_to_vec3h(v2->screen_space),
				vec4_to_vec3h(v0->screen_space)));
	if (c->front_face == GL_CW)
		normal = negate_vec3(normal);
	if (dot_vec3s(normal, tmpvec3) <= 0)
		return (0);
	return (1);
}
