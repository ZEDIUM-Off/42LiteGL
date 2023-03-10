/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_stencil_mask.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:18:09 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 09:20:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_stencil_mask(t_GLContext *c, t_gl_uint mask)
{
	c->stencil_writemask = mask;
	c->stencil_writemask_back = mask;
}

void	gl_stencil_mask_separate(t_GLContext *c, t_gl_enum face, t_gl_uint mask)
{
	if (face < GL_FRONT || face > GL_FRONT_AND_BACK)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (face == GL_FRONT_AND_BACK)
	{
		gl_stencil_mask(mask);
		return ;
	}
	if (face == GL_FRONT)
		c->stencil_writemask = mask;
	else
		c->stencil_writemask_back = mask;
}
