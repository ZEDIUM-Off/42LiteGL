/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_depth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:26:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 12:27:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_clear_depth(t_GLContext *c, t_gl_clampd depth)
{
	c->clear_depth = clampf_01(depth);
}

void	gl_depth_func(t_GLContext *c, t_gl_enum func)
{
	if (func < GL_LESS || func > GL_NEVER)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	c->depth_func = func;
}

void	gl_depth_mask(t_GLContext *c, t_gl_boolean flag)
{
	c->depth_mask = flag;
}

void	gl_depth_range(t_GLContext *c, t_gl_clampf near, t_gl_clampf far)
{
	c->depth_range_near = clampf_01(near);
	c->depth_range_far = clampf_01(far);
}
