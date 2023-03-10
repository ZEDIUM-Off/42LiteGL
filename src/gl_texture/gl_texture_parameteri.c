/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_texture_parameteri.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:19:09 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 10:20:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_texture_parameteri(
	t_GLContext *c, t_gl_uint texture, t_gl_enum pname, t_gl_int param)
{
	if (texture >= c->textures.size)
	{
		if (!c->error)
			c->error = GL_INVALID_OPERATION;
		return ;
	}
	set_texparami(&c->textures.a[texture], pname, param);
}
