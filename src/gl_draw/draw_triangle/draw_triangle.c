/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:01:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:25:47 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	draw_triangle_final(
	t_GLContext *c, t_glVertex **v, unsigned int provoke)
{
	int	front_facing;

	v[0]->screen_space = mult_mat4_vec4(c->vp_mat, v[0]->clip_space);
	v[1]->screen_space = mult_mat4_vec4(c->vp_mat, v[1]->clip_space);
	v[2]->screen_space = mult_mat4_vec4(c->vp_mat, v[2]->clip_space);
	front_facing = is_front_facing(v[0], v[1], v[2]);
	if (c->cull_face)
	{
		if (c->cull_mode == GL_FRONT_AND_BACK)
			return ;
		if (c->cull_mode == GL_BACK && !front_facing)
			return ;
		if (c->cull_mode == GL_FRONT && front_facing)
			return ;
	}
	c->builtins.gl_FrontFacing = front_facing;
	if (front_facing)
		c->draw_triangle_front(c, v, provoke);
	else
		c->draw_triangle_back(c, v, provoke);
}

void	draw_triangle(t_GLContext *c, t_glVertex **v, unsigned int provoke)
{
	int	c_or;
	int	c_and;

	c_and = v[0]->clip_code & v[1]->clip_code & v[2]->clip_code;
	if (c_and != 0)
		return ;
	c_or = v[0]->clip_code | v[1]->clip_code | v[2]->clip_code;
	if (c_or == 0)
		draw_triangle_final(c, v, provoke);
	else
		draw_triangle_clip(c, v, provoke, 0);
}
