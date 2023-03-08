/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVertex_insert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:03:18 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:05:19 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_insert_gl_vertex(t_cvector_gl_vertex *vec, size_t i, t_gl_vertex a)
{
	t_gl_vertex	*tmp;
	size_t		tmp_sz;

	if (vec->capacity > vec->size)
	{
		ft_memmove(&vec->a[i + 1], &vec->a[i],
			(vec->size - i) * sizeof(t_gl_vertex));
		vec->a[i] = a;
	}
	else
	{
		tmp_sz = (vec->capacity + 1) * 2;
		tmp = (t_gl_vertex *)ft_realloc(vec->a, sizeof(t_gl_vertex) * tmp_sz);
		if (!tmp)
			return (ft_assert(tmp != NULL), 0);
		vec->a = tmp;
		ft_memmove(&vec->a[i + 1], &vec->a[i],
			(vec->size - i) * sizeof(t_gl_vertex));
		vec->a[i] = a;
		vec->capacity = tmp_sz;
	}
	vec->size++;
	return (1);
}

int	cvec_insert_array_gl_vertex(
	t_cvector_gl_vertex *vec, size_t i, t_gl_vertex *a, size_t num)
{
	t_gl_vertex	*tmp;
	size_t		tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_SZ;
		tmp = (t_gl_vertex *)ft_realloc(vec->a, sizeof(t_gl_vertex) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	ft_memmove(&vec->a[i + num], &vec->a[i],
		(vec->size - i) * sizeof(t_gl_vertex));
	ft_memmove(&vec->a[i], a, num * sizeof(t_gl_vertex));
	vec->size += num;
	return (1);
}
