/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_tex_sub_image_3D.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:46:57 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 19:36:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_tex_sub_image_3d(
	t_gl_context *c, t_gl_enum target,
	t_tex_image_params *params, t_gl_void *data)
{
	int		cur_tex;
	t_u32	*texdata;
	int		i;
	int		j;

	cur_tex = c->bound_textures[target - GL_TEXTURE_UNBOUND - 1];
	texdata = (t_u32 *)c->textures.a[cur_tex].data;
	j = 0;
	while (j < params->depth)
	{
		i = 0;
		while (i++ < params->height)
			ft_memcpy(&texdata[(params->zoffset + j) * c->textures.a[cur_tex].w
				* c->textures.a[cur_tex].h + (params->yoffset + i)
				* c->textures.a[cur_tex].w + params->xoffset],
				&data[j * params->width * params->height + i * params->width],
				params->width * sizeof(t_u32));
		j++;
	}
}
