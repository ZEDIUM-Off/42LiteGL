/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_is_enable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:13:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_boolean	gl_is_enable(t_gl_context *c, t_gl_enum cap)
{
	if (cap == GL_DEPTH_TEST)
		return (c->depth_test);
	else if (cap == GL_LINE_SMOOTH)
		return (c->line_smooth);
	else if (cap == GL_CULL_FACE)
		return (c->cull_face);
	else if (cap == GL_DEPTH_CLAMP)
		return (c->depth_clamp);
	else if (cap == GL_BLEND)
		return (c->blend);
	else if (cap == GL_COLOR_LOGIC_OP)
		return (c->logic_ops);
	else if (cap == GL_POLYGON_OFFSET_FILL)
		return (c->poly_offset);
	else if (cap == GL_SCISSOR_TEST)
		return (c->scissor_test);
	else if (cap == GL_STENCIL_TEST)
		return (c->stencil_test);
	else if (!c->error)
		c->error = GL_INVALID_ENUM;
	return (GL_FALSE);
}
