/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_stencil_op_separate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:36:00 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 21:12:41 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	front_or_back(
	t_gl_context *c, t_gl_enum face, t_gl_enum *sfail_dpfail, t_gl_enum dppass)
{
	if (face == GL_FRONT)
	{
		c->stencil_sfail = sfail_dpfail[0];
		c->stencil_dpfail = sfail_dpfail[1];
		c->stencil_dppass = dppass;
	}
	else
	{
		c->stencil_sfail_back = sfail_dpfail[0];
		c->stencil_dpfail_back = sfail_dpfail[1];
		c->stencil_dppass_back = dppass;
	}
}

void	gl_stencil_op_separate(
	t_gl_context *c, t_gl_enum face, t_gl_enum *sfail_dpfail, t_gl_enum dppass)
{
	if (face < GL_FRONT || face > GL_FRONT_AND_BACK)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (face == GL_FRONT_AND_BACK)
	{
		gl_stencil_op(c, sfail_dpfail[0], sfail_dpfail[1], dppass);
		return ;
	}
	if (((sfail_dpfail[1] < GL_INVERT || sfail_dpfail[1] > GL_DECR_WRAP)
			&& sfail_dpfail[1] != GL_ZERO) || ((sfail_dpfail[0] < GL_INVERT
				|| sfail_dpfail[0] > GL_DECR_WRAP)
			&& sfail_dpfail[1] != GL_ZERO)
		|| ((dppass < GL_INVERT || dppass > GL_DECR_WRAP)
			&& sfail_dpfail[1] != GL_ZERO))
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	front_or_back(c, face, sfail_dpfail, dppass);
}
