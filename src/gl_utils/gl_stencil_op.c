/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_stencil_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:32:41 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 21:15:39 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_stencil_op(
	t_gl_context*c, t_gl_enum sfail, t_gl_enum dpfail, t_gl_enum dppass)
{
	if (((sfail < GL_INVERT || sfail > GL_DECR_WRAP) && sfail != GL_ZERO)
		|| ((dpfail < GL_INVERT || dpfail > GL_DECR_WRAP) && sfail != GL_ZERO)
		|| ((dppass < GL_INVERT || dppass > GL_DECR_WRAP) && sfail != GL_ZERO))
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	c->stencil_sfail = sfail;
	c->stencil_dpfail = dpfail;
	c->stencil_dppass = dppass;
	c->stencil_sfail_back = sfail;
	c->stencil_dpfail_back = dpfail;
	c->stencil_dppass_back = dppass;
}
