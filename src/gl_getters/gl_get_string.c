/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:15:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/08 15:40:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_ubyte	*gt_get_string(t_gl_enum name)
{
	static t_gl_ubyte	vendor[];
	static t_gl_ubyte	renderer[];
	static t_gl_ubyte	version[];
	static t_gl_ubyte	shading_language[];

	vendor = "Matisse Chenavas";
	renderer = "LiteGL 42 friendly (using mlx)";
	version = "LiteGL v1.42 - close to OpenGL 3.x";
	shading_language = "full C99 bébé ! 😎";
	if (name == GL_VENDOR)
		return (vendor);
	if (name == GL_RENDERER)
		return (renderer);
	if (name == GL_VERSION)
		return (version);
	if (name == GL_SHADING_LANGUAGE_VERSION)
		return (shading_language);
	if (!c->error)
		c->error = GL_INVALID_ENUM;
	return (0);
}
