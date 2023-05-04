/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_viewport.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:09:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/03 16:33:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_viewport(t_gl_context *c, int xy[2], t_gl_sizei wh[2])
{
	if (wh[0] < 0 || wh[1] < 0)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	make_viewport_matrix(c->vp_mat, (float [2]){xy[0], xy[1]},
		(t_u32 [2]){wh[0], wh[1]}, 1);
	c->x_min = xy[0];
	c->y_min = xy[1];
	c->x_max = xy[0] + wh[0];
	c->y_max = xy[1] + wh[1];
}
