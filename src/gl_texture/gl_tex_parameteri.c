/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_tex_parameteri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:53:52 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_tex_parameteri(
	t_gl_context *c, t_gl_enum target, t_gl_enum pname, t_gl_int param)
{
	if (target != GL_TEXTURE_1D && target != GL_TEXTURE_2D
		&& target != GL_TEXTURE_3D && target != GL_TEXTURE_2D_ARRAY
		&& target != GL_TEXTURE_RECTANGLE && target != GL_TEXTURE_CUBE_MAP)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	target -= GL_TEXTURE_UNBOUND + 1;
	set_texparami(&c->textures.a[c->bound_textures[target]], pname, param);
}
