/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texparami.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:58:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 14:17:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	param_min_filter(t_GLContext *c, t_gl_texture *tex, t_gl_int param)
{
	if (param != GL_NEAREST && param != GL_LINEAR
		&& param != GL_NEAREST_MIPMAP_NEAREST
		&& param != GL_NEAREST_MIPMAP_LINEAR
		&& param != GL_LINEAR_MIPMAP_NEAREST
		&& param != GL_LINEAR_MIPMAP_LINEAR)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return (0);
	}
	if (param == GL_NEAREST_MIPMAP_NEAREST || param == GL_NEAREST_MIPMAP_LINEAR)
		param = GL_NEAREST;
	if (param == GL_LINEAR_MIPMAP_NEAREST || param == GL_LINEAR_MIPMAP_LINEAR)
		param = GL_LINEAR;
	tex->min_filter = param;
	return (1);
}

void	warp_param(
	t_GLContext *c, t_gl_texture *tex, t_gl_enum pname, t_gl_int param)
{
	if (param != GL_REPEAT && param != GL_CLAMP_TO_EDGE
		&& param != GL_CLAMP_TO_BORDER && param != GL_MIRRORED_REPEAT)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (pname == GL_TEXTURE_WRAP_S)
		tex->wrap_s = param;
	else if (pname == GL_TEXTURE_WRAP_T)
		tex->wrap_t = param;
	else if (pname == GL_TEXTURE_WRAP_R)
		tex->wrap_r = param;
}

void	set_texparami(
	t_GLContext *c, t_gl_texture *tex, t_gl_enum pname, t_gl_int param)
{
	if (pname != GL_TEXTURE_MIN_FILTER && pname != GL_TEXTURE_MAG_FILTER
		&& pname != GL_TEXTURE_WRAP_S && pname != GL_TEXTURE_WRAP_T
		&& pname != GL_TEXTURE_WRAP_R)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (pname == GL_TEXTURE_MIN_FILTER)
		if (!param_min_filter(c, tex, param))
			return ;
	else if (pname == GL_TEXTURE_MAG_FILTER)
	{
		if (param != GL_NEAREST && param != GL_LINEAR)
		{
			if (!c->error)
				c->error = GL_INVALID_ENUM;
			return ;
		}
		tex->mag_filter = param;
	}
	warp_param(c, tex, pname, param);
}
