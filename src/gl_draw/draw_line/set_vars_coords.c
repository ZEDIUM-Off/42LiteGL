/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:36:15 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/30 12:46:08 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	set_vars_coords(
		t_draw_line_shader_vars *vars, t_vec3 hp[2], t_vec4 *vertexes)
{
	vars->x[0] = hp[0].x;
	vars->x[1] = hp[1].x;
	vars->y[0] = hp[0].y;
	vars->y[1] = hp[1].y;
	vars->z[0] = hp[0].z;
	vars->z[1] = hp[1].z;
	vars->w[0] = vertexes[0].w;
	vars->w[1] = vertexes[1].w;
}
