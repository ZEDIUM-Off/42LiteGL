/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_context.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:25:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/08 11:28:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	init_mlx_context(t_GLContext *c, t_gl_settings *s)
{
	t_mlx_context	mlx_ctx;

	mlx_ctx.mlx = mlx_init();
	mlx_ctx.mlx_win = mlx_new_win(mlx_ctx.mlx, s->w, s->h, s->title);
	mlx_ctx.img = mlx_new_image(mlx_ctx.mlx, s->w, s->h);
	mlx_ctx.img_addr = mlx_get_data_addr(mlx_ctx.img,
			&mlx_ctx.bpp, &mlx_ctx.line_len, &mlx_ctx.endian);
	c->mlx_ctx = mlx_ctx;
}
