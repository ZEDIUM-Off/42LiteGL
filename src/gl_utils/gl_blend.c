/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_blend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:27:41 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_blend_func(t_gl_context *c, t_gl_enum sfactor, t_gl_enum dfactor)
{
	if (sfactor < GL_ZERO || sfactor >= NUM_BLEND_FUNCS
		|| dfactor < GL_ZERO || dfactor >= NUM_BLEND_FUNCS)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	c->blend_sfactor = sfactor;
	c->blend_dfactor = dfactor;
}

void	gl_blend_equation(t_gl_context *c, t_gl_enum mode)
{
	if (mode < GL_FUNC_ADD || mode >= NUM_BLEND_EQUATIONS)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	c->blend_equation = mode;
}

void	gl_blend_color(t_gl_context *c, t_gl_clampf *color)
{
	set_vec4(c->blend_color, clampf_01(color[0]), clampf_01(color[1]),
		clampf_01(color[2]), clampf_01(color[3]));
}
