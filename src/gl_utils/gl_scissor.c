/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_scissor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:19:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 15:21:40 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_scissor(t_GLContext *c, t_gl_int *xy, t_gl_sizei *wh)
{
	if (width < 0 || height < 0)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	c->scissor_lx = xy[0];
	c->scissor_ly = xy[1];
	c->scissor_ux = xy[0] + wh[0];
	c->scissor_uy = y[1] + wh[1];
}