/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depthtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:54:41 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 17:26:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	depthtest(t_gl_context *c, float zval, float zbufval)
{
	if (!c->depth_mask)
		return (0);
	if (c->depth_func == GL_LESS)
		return (zval < zbufval);
	else if (c->depth_func == GL_LEQUAL)
		return (zval <= zbufval);
	else if (c->depth_func == GL_GREATER)
		return (zval > zbufval);
	else if (c->depth_func == GL_GEQUAL)
		return (zval >= zbufval);
	else if (c->depth_func == GL_EQUAL)
		return (zval == zbufval);
	else if (c->depth_func == GL_NOTEQUAL)
		return (zval != zbufval);
	else if (c->depth_func == GL_ALWAYS)
		return (1);
	else if (c->depth_func == GL_NEVER)
		return (0);
	return (0);
}
