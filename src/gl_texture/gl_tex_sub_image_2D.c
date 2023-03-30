/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_tex_sub_image_2D.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:36:57 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/30 10:24:43 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_tex_sub_image_2d(
	t_gl_context *c, t_gl_enum target,
	t_tex_image_params *params, t_gl_void *data)
{
	int		cur_tex;
	t_u32	*texdata;
	t_u32	*d;
	int		i;

	d = (t_u32 *)data;
	cur_tex = c->bound_textures[target - GL_TEXTURE_UNBOUND - 1];
	texdata = (t_u32 *)c->textures.a[cur_tex].data;
	i = 0;
	if (target == GL_TEXTURE_2D)
		while (i++ < params->height)
			ft_memcpy(&texdata[(params->yoffset + i) * c->textures.a[cur_tex].w
				+ params->xoffset], &d[i * params->width],
				params->width * sizeof(t_u32));
	else
	{
		cur_tex = c->bound_textures[
			GL_TEXTURE_CUBE_MAP - GL_TEXTURE_UNBOUND - 1];
		target -= GL_TEXTURE_CUBE_MAP_POSITIVE_X;
		while (i++ < params->height)
			ft_memcpy(&texdata[c->textures.a[cur_tex].w
				* c->textures.a[cur_tex].w * target + (params->yoffset + i)
				* c->textures.a[cur_tex].w + params->xoffset],
				&d[i * params->width], params->width * sizeof(t_u32));
	}
}
