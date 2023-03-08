/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVertex_Array_insert.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:55:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 15:46:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_insert_gl_vertex_array(
	t_cvector_gl_vertex_array *vec, size_t i, t_gl_vertex_array a)
{
	t_gl_vertex_array	*tmp;
	size_t				tmp_sz;

	if (vec->capacity > vec->size)
	{
		ft_memmove(&vec->a[i + 1], vec->a[i],
			sizeof(t_gl_vertex_array) * (vec->size - i));
		vec->a[i] = a;
	}
	else
	{
		tmp_sz = (vec->capacity + 1) * 2;
		tmp = (t_gl_vertex_array *)ft_realloc(
				vec->a, sizeof(t_gl_vertex_array) * tmp_sz);
		if (!tmp)
			return (ft_assert(tmp != NULL), 0);
		vec->a = tmp;
		ft_memmove(&vec->a[i + 1], &vec->a[i],
			sizeof(t_gl_vertex_array) * (vec->size - i));
		vec->a[i] = a;
		vec->capacity = tmp_sz;
	}
	vec->size++;
	return (1);
}

int	cvec_insert_array_gl_vertex_array(
	t_cvector_gl_vertex_array *vec, size_t i, t_gl_vertex_array *a, size_t n)
{
	t_gl_vertex_array	*tmp;
	size_t				tmp_sz;

	if (vec->capacity < vec->size + n)
	{
		tmp_sz = vec->capacity + n + CVEC_FLOAT_SIZE;
		tmp = (t_gl_vertex_array *)ft_realloc(
				vec->a, sizeof(t_gl_vertex_array) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	ft_memmove(&vec->a[i + n], &vec->a[i],
		sizeof(t_gl_vertex_array) * (vec->size - i));
	ft_memmove(&vec->a[i], a, sizeof(t_gl_vertex_array) * n);
	vec->size += n;
	return (1);
}
