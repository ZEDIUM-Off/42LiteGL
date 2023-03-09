/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_stencil_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:23:01 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 15:25:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_stencil_func(
	t_GLContext *c, t_gl_enum func, t_gl_int ref, t_gl_uint mask)
{
	if (func < GL_LESS || func > GL_NEVER)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	c->stencil_func = func;
	c->stencil_func_back = func;
	if (ref > 255)
		ref = 255;
	if (ref < 0)
		ref = 0;
	c->stencil_ref = ref;
	c->stencil_ref_back = ref;
	c->stencil_valuemask = mask;
	c->stencil_valuemask_back = mask;
}
