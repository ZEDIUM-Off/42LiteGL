/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVertex_Array_push_pop.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:47:16 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 10:32:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_push_gl_vertex_array(
	t_cvector_gl_vertex_array *vec, t_gl_vertex_array a)
{
	t_gl_vertex_array	*tmp;
	size_t				tmp_sz;

	if (vec->capacity > vec->size)
		vec->a[vec->size++] = a;
	else
	{
		tmp_sz = (vec->capacity + 1) * 2;
		tmp = (t_gl_vertex_array *)ft_realloc(
				vec->a, sizeof(t_gl_vertex_array) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->a[vec->size++] = a;
		vec->capacity = tmp_sz;
	}
	return (1);
}

t_gl_vertex_array	cvec_pop_gl_vertex_array(t_cvector_gl_vertex_array *vec)
{
	return (vec->a[--vec->size]);
}
