/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_stencil_func_separate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:25:45 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 21:21:33 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	front_or_back(
	t_gl_context *c, t_gl_enum *face_func, t_gl_int ref, t_gl_uint mask)
{
	if (face_func[0] == GL_FRONT)
	{
		c->stencil_func = face_func[1];
		c->stencil_ref = ref;
		c->stencil_valuemask = mask;
	}
	else
	{
		c->stencil_func_back = face_func[1];
		c->stencil_ref_back = ref;
		c->stencil_valuemask_back = mask;
	}
}

void	gl_stencil_func_separate(
	t_gl_context *c, t_gl_enum *face_func, t_gl_int ref, t_gl_uint mask)
{
	if (face_func[0] < GL_FRONT || face_func[0] > GL_FRONT_AND_BACK)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (face_func[0] == GL_FRONT_AND_BACK)
		return (gl_stencil_func(c, face_func[1], ref, mask));
	if (face_func[1] < GL_LESS || face_func[1] > GL_NEVER)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (ref > 255)
		ref = 255;
	if (ref < 0)
		ref = 0;
	front_or_back(c, face_func, ref, mask);
}
