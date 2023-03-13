/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_gen_vertex_arrays.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:35 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 19:36:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_gen_vertex_arrays(t_gl_context *c, t_gl_sizei n, t_gl_uint *arrays)
{
	size_t				i;
	t_gl_vertex_array	tmp;

	init_gl_vertex_array(&tmp);
	tmp.deleted = GL_FALSE;
	i = 1;
	--n;
	while (i < c->vertex_arrays.size && n >= 0)
	{
		if (c->vertex_arrays.a[i].deleted)
		{
			c->vertex_arrays.a[i] = tmp;
			arrays[n--] = i;
		}
		i++;
	}
	while (n >= 0)
	{
		cvec_push_gl_vertex_array(&c->vertex_arrays, tmp);
		arrays[n--] = c->vertex_arrays.size - 1;
	}
}
