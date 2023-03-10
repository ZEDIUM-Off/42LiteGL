/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_bind_vertex_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:59:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 15:00:09 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_bind_vertex_array(t_GLContext *c, t_gl_uint array)
{
	if (array < c->vertex_arrays.size
		&& c->vertex_arrays.a[array].deleted == GL_FALSE)
		c->cur_vertex_array = array;
	else if (!c->error)
		c->error = GL_INVALID_OPERATION;
}
