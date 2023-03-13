/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_tex_image_1D.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:24:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 19:32:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	set_components(t_gl_context *c, int *components, t_gl_enum format)
{
	if (format == GL_RED)
		*components = 1;
	else if (format == GL_RG)
		*components = 2;
	else if (format == GL_RGB || format == GL_BGR)
		*components = 3;
	else if (format == GL_RGBA || format == GL_BGRA)
		*components = 4;
	else
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return (0);
	}
	return (1);
}

void	copy_img_data(
	t_gl_context *c, int cur_tex,
	t_gl_void *data, int components)
{
	t_u32	*texdata;

	free(c->textures.a[cur_tex].data);
	c->textures.a[cur_tex].data = (t_u8 *)malloc(
			c->textures.a[cur_tex].w * components);
	if (!c->textures.a[cur_tex].data)
	{
		if (!c->error)
			c->error = GL_OUT_OF_MEMORY;
		return ;
	}
	texdata = (t_u32 *)c->textures.a[cur_tex].data;
	if (data)
		ft_memcpy(&texdata[0], data, c->textures.a[cur_tex].w * sizeof(t_u32));
	c->textures.a[cur_tex].user_owned = GL_FALSE;
}

void	gl_tex_image_1d(
	t_gl_context *c, t_gl_enum target,
	t_tex_image_params *params, t_gl_void *data)
{
	int	cur_tex;
	int	components;

	if (target != GL_TEXTURE_1D)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (params->border)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	cur_tex = c->bound_textures[target - GL_TEXTURE_UNBOUND - 1];
	c->textures.a[cur_tex].w = params->width;
	if (params->type != GL_UNSIGNED_BYTE)
		return ;
	if (!set_components(c, &components, params->format))
		return ;
	copy_img_data(c, cur_tex, data, components);
}
