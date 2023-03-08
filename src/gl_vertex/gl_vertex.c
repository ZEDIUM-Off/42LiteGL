/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_vertex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:24:07 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 12:07:31 by  mchenava        ###   ########.fr       */
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

void	gl_vertex_attrib_pointer(t_GLContext *c, t_gl_uint index,
	t_glVertex_Attrib attr, const t_gl_void *pointer)
{
	t_glVertex_Attrib	*v;

	if (index >= GL_MAX_VERTEX_ATTRIBS || attr.size < 1 || attr.size > 4
		|| (!c->bound_buffers[GL_ARRAY_BUFFER - GL_ARRAY_BUFFER] && pointer))
	{
		if (!c->error)
			c->error = GL_INVALID_OPERATION;
		return ;
	}
	if (attr.type != GL_FLOAT)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	v = &(c->vertex_arrays.a[c->cur_vertex_array].vertex_attribs[index]);
	v->size = attr.size;
	v->type = atrr.type;
	if (attr.stride)
		v->stride = attr.stride;
	else
		v->stride = attr.size * attr.sizeof(t_gl_float);
	v->offset = (GLsizeiptr)pointer;
	v->normalized = attr.normalized;
	v->buf = c->bound_buffers[GL_ARRAY_BUFFER - GL_ARRAY_BUFFER];
}
