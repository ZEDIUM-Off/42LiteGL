/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_point_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:11:56 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 15:14:16 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_point_size(t_GLContext *c, t_gl_float size)
{
	if (size <= 0.0f)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	c->point_size = size;
}

void	gl_point_parameteri(t_GLContext *c, t_gl_enum pname, t_gl_int param)
{
	if (pname != GL_POINT_SPRITE_COORD_ORIGIN
		|| (param != GL_LOWER_LEFT && param != GL_UPPER_LEFT))
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	c->point_spr_origin = param;
}
