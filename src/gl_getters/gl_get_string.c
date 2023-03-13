/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:15:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 16:02:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

char	*gl_get_string(t_gl_context *c, t_gl_enum name)
{
	static char	*vendor;
	static char	*renderer;
	static char	*version;
	static char	*shading_language;

	vendor = new_str("Matisse Chenavas");
	renderer = new_str("LiteGL 42 friendly (using mlx)");
	version = new_str("LiteGL v0.42 - close to OpenGL 3.x");
	shading_language = new_str("full C99 bébé ! 😎");
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
