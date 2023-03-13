/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_vertex_attrib_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:44:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 19:38:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_vertex_attrib_pointer(t_gl_context *c, t_gl_uint index,
	t_gl_vertex_attrib attr, const t_gl_void *pointer)
{
	t_gl_vertex_attrib	*v;

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
	v->type = attr.type;
	if (attr.stride)
		v->stride = attr.stride;
	else
		v->stride = attr.size * sizeof(t_gl_float);
	v->offset = (t_gl_sizeiptr)pointer;
	v->normalized = attr.normalized;
	v->buf = c->bound_buffers[GL_ARRAY_BUFFER - GL_ARRAY_BUFFER];
}
