/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_get_booleanv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:24:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 16:04:32 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_get_booleanv(t_gl_context *c, t_gl_enum pname, t_gl_boolean *params)
{
	if (pname == GL_DEPTH_TEST)
		*params = c->depth_test;
	else if (pname == GL_LINE_SMOOTH)
		*params = c->line_smooth;
	else if (pname == GL_CULL_FACE)
		*params = c->cull_face;
	else if (pname == GL_DEPTH_CLAMP)
		*params = c->depth_clamp;
	else if (pname == GL_BLEND)
		*params = c->blend;
	else if (pname == GL_COLOR_LOGIC_OP)
		*params = c->logic_ops;
	else if (pname == GL_POLYGON_OFFSET_FILL)
		*params = c->poly_offset;
	else if (pname == GL_SCISSOR_TEST)
		*params = c->scissor_test;
	else if (pname == GL_STENCIL_TEST)
		*params = c->stencil_test;
	else if (!c->error)
		c->error = GL_INVALID_ENUM;
}
