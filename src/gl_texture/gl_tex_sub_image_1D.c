/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_tex_sub_image_1D.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:32:41 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 14:36:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_tex_sub_image_1d(
	t_GLContext *c, t_gl_enum target,
	t_tex_image_params *params, t_gl_void *data)
{
	int		cur_tex;
	t_u32	*texdata;

	cur_tex = c->bound_textures.a[target - GL_TEXTURE_UNBOUND - 1];
	texdata = (t_u32 *)c->textures.a[cur_tex].data;
	ft_memcpy(&texdata[params->xoffset], data, params->width * sizeof(t_u32));
}
