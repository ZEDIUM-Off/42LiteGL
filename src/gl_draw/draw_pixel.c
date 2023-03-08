/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:27:36 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/28 10:50:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	do_depth_test(t_GLContext *c, t_vec2 pos, float z, u8 *stencil_dest)
{
	float	dest_depth;
	float	src_depth;
	int		depth_result;

	dest_depth = ((float *)c->zbuf.lastrow)[-pos.y * c->zbuf.w + pos.x];
	src_depth = z;
	depth_result = depth_test(c, src_depth, dest_depth);
	if (c->stencil_test)
		stencil_op(c, 1, depth_result, stencil_dest);
	if (!depth_result)
		return (0);
	((float *)c->zbuf.lastrow)[(-(int)pos.y)
		* c->zbuf.w + (int)pos.x] = src_depth;
	return (1);
}

int	do_test(t_GLContext *c, t_vec2 pos, float z)
{
	u8		*stencil_dest;

	if (c->scissor_test)
		if ((int)pos.x < c->scissor_lx || (int)pos.y < c->scissor_ly
			|| (int)pos.x >= c->scissor_ux || (int)pos.y >= c->scissor_uy)
			return (0);
	stencil_dest = &c->stencil_buf.lastrow[(-(int)pos.y)
		* c->stencil_buf.w + (int)pos.x];
	if (c->stencil_test)
	{
		if (!stencil_test(c, *stencil_dest))
		{
			stencil_op(c, 0, 1, stencil_dest);
			return (0);
		}
	}
	if (c->depth_test)
	{
		if (!do_depth_test(c, pos, z, stencil_dest))
			return (0);
	}
	else if (c->stencil_test)
		stencil_op(c, 1, 1, stencil_dest);
	return (1);
}

t_Color	blending(t_GLContext *c, t_vec4 cf, t_vec2 pos)
{
	t_Color		dest_color;
	t_Color		src_color;
	u32			*dest;

	dest = &((u32 *)c->back_buffer.lastrow)[(-(int)pos.y)
		* c->back_buffer.w + (int)pos.x];
	dest_color = make_color((*dest & c->r_mask) >> c->r_shift,
			(*dest & c->g_mask) >> c->g_shift,
			(*dest & c->b_mask) >> c->b_shift,
			(*dest & c->a_mask) >> c->a_shift);
	if (c->blend)
		src_color = blend_pixel(c, cf, color_to_vec4(dest_color));
	else
	{
		cf.x = clampf_01(cf.x);
		cf.y = clampf_01(cf.y);
		cf.z = clampf_01(cf.z);
		cf.w = clampf_01(cf.w);
		src_color = vec4_to_color(cf);
	}
	if (c->logic_ops)
		src_color = logic_ops_pixel(c, src_color, dest_color);
	return (src_color);
}

void	draw_pixel(t_GLConext *c, t_vec4 cf, t_vec2 pos, float z)
{
	t_Color	color;

	if (!do_test(c, pos, z))
		return ;
	color = blending(c, cf, pos);
	pixel_put(c->mlx_env, (int)pos.x, (int)pos.y, color);
}
