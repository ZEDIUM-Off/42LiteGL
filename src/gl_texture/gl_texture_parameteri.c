/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_texture_parameteri.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:19:09 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 19:34:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_texture_parameteri(
	t_gl_context *c, t_gl_uint texture, t_gl_enum pname, t_gl_int param)
{
	if (texture >= c->textures.size)
	{
		if (!c->error)
			c->error = GL_INVALID_OPERATION;
		return ;
	}
	set_texparami(c, &c->textures.a[texture], pname, param);
}
