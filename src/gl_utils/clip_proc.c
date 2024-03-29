/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:45:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/30 11:14:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	init_clip_proc(t_gl_context *c)
{
	c->clip_proc[0] = clip_zmin;
	c->clip_proc[1] = clip_zmax;
	c->clip_proc[2] = clip_xmin;
	c->clip_proc[3] = clip_xmax;
	c->clip_proc[4] = clip_ymin;
	c->clip_proc[5] = clip_ymax;
}
