/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_vertex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:24:07 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 15:46:51 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_enable_vertex_attrib_array(t_GLContext *c, t_gl_uint index)
{
	c->vertex_arrays.a[c->cur_vertex_array].vertex_attribs[index].enabled = \
	GL_TRUE;
}

void	gl_disable_vertex_attrib_array(t_GLContext *c, t_gl_uint index)
{
	c->vertex_arrays.a[c->cur_vertex_array].vertex_attribs[index].enabled = \
	GL_FALSE;
}
