/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_bind_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:34:18 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_bind_texture(t_gl_context *c, t_gl_enum target, t_gl_uint texture)
{
	if (target < GL_TEXTURE_1D || target >= GL_NUM_TEXTURE_TYPES)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	target -= GL_TEXTURE_UNBOUND + 1;
	if (texture < c->textures.size && !c->textures.a[texture].deleted)
	{
		if (c->textures.a[texture].type == GL_TEXTURE_UNBOUND)
		{
			c->bound_textures[target] = texture;
			init_tex(c->textures.a[texture], target);
		}
		else if (c->textures.a[texture].type == target)
			c->bound_textures[target] = texture;
		else if (!c->error)
			c->error = GL_INVALID_OPERATION;
	}
	else if (!c->error)
		c->error = GL_INVALID_VALUE;
}
