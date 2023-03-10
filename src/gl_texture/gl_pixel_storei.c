/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_pixel_storei.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:21:01 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 10:22:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_pixel_storei(t_GLContext *c, t_gl_enum pname, t_gl_int param)
{
	if (pname != GL_UNPACK_ALIGNMENT && pname != GL_PACK_ALIGNMENT)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (param != 1 && param != 2 && param != 4 && param != 8)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	if (pname == GL_UNPACK_ALIGNMENT)
		c->unpack_alignment = param;
	else if (pname == GL_PACK_ALIGNMENT)
		c->pack_alignment = param;
}
