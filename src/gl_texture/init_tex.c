/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:38:53 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/30 10:20:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	init_tex(t_gl_texture tex, t_gl_enum target)
{
	if (tex.deleted)
		return ;
	tex.type = target;
	tex.mag_filter = GL_LINEAR;
	tex.min_filter = GL_LINEAR;
	tex.wrap_s = GL_REPEAT;
	tex.wrap_t = GL_REPEAT;
	tex.wrap_r = GL_REPEAT;
	tex.data = NULL;
	tex.deleted = GL_FALSE;
	tex.user_owned = GL_TRUE;
	tex.format = GL_RGBA;
	tex.w = 0;
	tex.h = 0;
	tex.d = 0;
}
