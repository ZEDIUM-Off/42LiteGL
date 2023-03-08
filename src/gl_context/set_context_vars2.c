/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_context_vars2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:40:59 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/08 13:48:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	set_last_vars(t_GLContext *c, t_context_settings *s)
{
	c->poly_units = 0.0f;
	c->scissor_lx = 0;
	c->scissor_ly = 0;
	c->scissor_ux = s->w;
	c->scissor_uy = s->h;
	c->unpack_alignment = 4;
	c->pack_alignment = 4;
	c->draw_triangle_front = draw_triangle_fill;
	c->draw_triangle_back = draw_triangle_fill;
	c->error = GL_NO_ERROR;
}

void	set_next_vars(t_GLContext *c, t_context_settings *s)
{
	c->stencil_writemask = -1;
	c->stencil_writemask_back = -1;
	c->stencil_ref = 0;
	c->stencil_ref_back = 0;
	c->stencil_valuemask = -1;
	c->stencil_valuemask_back = -1;
	c->stencil_func = GL_ALWAYS;
	c->stencil_func_back = GL_ALWAYS;
	c->stencil_sfail = GL_KEEP;
	c->stencil_dpfail = GL_KEEP;
	c->stencil_dppass = GL_KEEP;
	c->stencil_sfail_back = GL_KEEP;
	c->stencil_dpfail_back = GL_KEEP;
	c->stencil_dppass_back = GL_KEEP;
	c->logic_func = GL_COPY;
	c->blend_sfactor = GL_ONE;
	c->blend_dfactor = GL_ZERO;
	c->blend_equation = GL_FUNC_ADD;
	c->depth_func = GL_LESS;
	c->line_smooth = GL_FALSE;
	c->poly_mode_front = GL_FILL;
	c->poly_mode_back = GL_FILL;
	c->point_spr_origin = GL_UPPER_LEFT;
	c->poly_factor = 0.0f;
	set_last_vars(c, s);
}
