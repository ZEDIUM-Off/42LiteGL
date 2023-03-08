/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:19:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	pixel_put(t_mlx_env	*env, int x, int y, int color)
{
	char	*dst;
	int		i;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	i = env->bpp - 8;
	dst = env->img_addr + (y * env->line_len + x * (env->bpp / 8));
	while (i >= 0)
	{
		if (env->endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (env->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
