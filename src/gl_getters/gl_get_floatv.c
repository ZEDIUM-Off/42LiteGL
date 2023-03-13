/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_get_floatv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:34:54 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_get_floatv(t_gl_context *c, t_gl_enum pname, t_gl_float *params)
{
	if (pname == GL_POLYGON_OFFSET_FACTOR)
		*params = c->poly_factor;
	else if (pname == GL_POLYGON_OFFSET_UNITS)
		*params = c->poly_units;
	else if (pname == GL_POINT_SIZE)
		*params = c->point_size;
	else if (pname == GL_DEPTH_CLEAR_VALUE)
		*params = c->clear_depth;
	else if (pname == GL_DEPTH_RANGE)
	{
		params[0] = c->depth_range_near;
		params[1] = c->depth_range_far;
	}
	else if (!c->error)
		c->error = GL_INVALID_ENUM;
}
