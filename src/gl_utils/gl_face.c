/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_face.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:51:44 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_cull_face(t_gl_context *c, t_gl_enum mode)
{
	if (mode != GL_FRONT && mode != GL_BACK && mode != GL_FRONT_AND_BACK)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	c->cull_mode = mode;
}

void	gl_front_face(t_gl_context *c, t_gl_enum mode)
{
	if (mode != GL_CCW && mode != GL_CW)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	c->front_face = mode;
}
