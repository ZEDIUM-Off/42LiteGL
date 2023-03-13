/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gl_vertex_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:24:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 15:25:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	init_gl_vertex_array(t_gl_vertex_array *v)
{
	int	i;

	v->deleted = GL_FALSE;
	i = 0;
	while (i < GL_MAX_VERTEX_ATTRIBS)
		init_gl_vertex_attrib(&v->vertex_attribs[i++]);
}
