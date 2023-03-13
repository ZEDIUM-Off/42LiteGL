/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_on_off.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:45:45 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 21:17:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_enable(t_gl_context *c, t_gl_enum cap)
{
	if (cap == GL_CULL_FACE)
		c->cull_face = GL_TRUE;
	else if (cap == GL_DEPTH_TEST)
		c->depth_test = GL_TRUE;
	else if (cap == GL_DEPTH_CLAMP)
		c->depth_clamp = GL_TRUE;
	else if (cap == GL_LINE_SMOOTH)
		c->line_smooth = GL_TRUE;
	else if (cap == GL_BLEND)
		c->blend = GL_TRUE;
	else if (cap == GL_COLOR_LOGIC_OP)
		c->logic_ops = GL_TRUE;
	else if (cap == GL_POLYGON_OFFSET_FILL)
		c->poly_offset = GL_TRUE;
	else if (cap == GL_SCISSOR_TEST)
		c->scissor_test = GL_TRUE;
	else if (cap == GL_STENCIL_TEST)
		c->stencil_test = GL_TRUE;
	else if (!c->error)
		c->error = GL_INVALID_ENUM;
}

void	gl_disable(t_gl_context *c, t_gl_enum cap)
{
	if (cap == GL_CULL_FACE)
		c->cull_face = GL_FALSE;
	else if (cap == GL_DEPTH_TEST)
		c->depth_test = GL_FALSE;
	else if (cap == GL_DEPTH_CLAMP)
		c->depth_clamp = GL_FALSE;
	else if (cap == GL_LINE_SMOOTH)
		c->line_smooth = GL_FALSE;
	else if (cap == GL_BLEND)
		c->blend = GL_FALSE;
	else if (cap == GL_COLOR_LOGIC_OP)
		c->logic_ops = GL_FALSE;
	else if (cap == GL_POLYGON_OFFSET_FILL)
		c->poly_offset = GL_FALSE;
	else if (cap == GL_SCISSOR_TEST)
		c->scissor_test = GL_FALSE;
	else if (cap == GL_STENCIL_TEST)
		c->stencil_test = GL_FALSE;
	else if (!c->error)
		c->error = GL_INVALID_ENUM;
}
