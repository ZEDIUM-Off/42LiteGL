/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:02:49 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 13:08:17 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	make_cylindrical(
	t_cvector_vec3 *verts, t_cvector_ivec3 *tris,
	t_cvector_vec2 *tex, t_cylinder_params *params)
{
	
}

void	make_cylinder(
	t_cvector_vec3 *verts, t_cvector_ivec3 *tris,
	t_cvector_vec2 *tex, t_cylinder_params *params)
{
	params->stacks = 1;
	make_cylindrical(verts, tris, tex, params);
}
