/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_draw_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:21:06 by mchenava          #+#    #+#             */
/*   Updated: 2024/03/04 15:25:30 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	lgl_draw_frame(t_gl_context *c)
{
	t_frag_func			frag_shader;
	t_shader_builtins	builtins;
	int					x;
	int					y;

	frag_shader = c->programs.a[c->cur_program].fragment_shader;
	y = 0;
	while (y < c->back_buffer.h)
	{
		x = 0;
		while (x < c->back_buffer.w)
		{
			builtins.gl_frag_coord.x = x + 0.5f;
			builtins.gl_frag_coord.y = y + 0.5f;
			builtins.discard = GL_FALSE;
			frag_shader(NULL, &builtins, c->programs.a[c->cur_program].uniform);
			if (!builtins.discard)
				draw_pixel(c, builtins.gl_frag_color, (t_vec2){x, y}, 0.0f);
			x++;
		}
		y++;
	}
}
