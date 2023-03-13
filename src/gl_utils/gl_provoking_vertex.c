/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_provoking_vertex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:44:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:15 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_provoking_vertex(t_gl_context *c, t_gl_enum mode)
{
	if (mode != GL_FIRST_VERTEX_CONVENTION && mode != GL_LAST_VERTEX_CONVENTION)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	c->provoking_vert = mode;
}
