/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:15:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/04 12:52:57 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

char	*gl_get_string(t_gl_context *c, t_gl_enum name)
{
	if (name == GL_VENDOR)
		return ("Matisse Chenavas");
	if (name == GL_RENDERER)
		return ("LiteGL 42 friendly");
	if (name == GL_VERSION)
		return ("LiteGL v0.42 - close to OpenGL 3.x");
	if (name == GL_SHADING_LANGUAGE_VERSION)
		return ("full C99 bébé ! 😎");
	if (!c->error)
		c->error = GL_INVALID_ENUM;
	return (0);
}
