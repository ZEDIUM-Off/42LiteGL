/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVertex_Array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:25:43 by  mchenava         #+#    #+#             */
/*   Updated: 2024/03/19 17:18:34 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_gl_vertex_array(
	t_cvector_gl_vertex_array *vec, size_t size, size_t capacity)
{
	vec->size = size;
	vec->capacity = vec->size + CVEC_SIZE;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (t_gl_vertex_array *)malloc(
			sizeof(t_gl_vertex_array) * vec->capacity);
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	return (1);
}

int	cvec_init_gl_vertex_array(
	t_cvector_gl_vertex_array *vec, t_gl_vertex_array *vals, size_t num)
{
	vec->size = num;
	vec->capacity = vec->size + CVEC_SIZE;
	vec->a = (t_gl_vertex_array *)malloc(
			sizeof(t_gl_vertex_array) * vec->capacity);
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	ft_memmove(vec->a, vals, sizeof(t_gl_vertex_array) * num);
	return (1);
}

t_cvector_gl_vertex_array	*cvec_gl_vertex_array_heap(
	size_t size, size_t capacity)
{
	t_cvector_gl_vertex_array	*vec;

	vec = (t_cvector_gl_vertex_array *)malloc(
			sizeof(t_cvector_gl_vertex_array));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->size = size;
	vec->capacity = vec->size + CVEC_SIZE;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (t_gl_vertex_array *)malloc(
			sizeof(t_gl_vertex_array) * vec->capacity);
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	return (vec);
}

t_cvector_gl_vertex_array	*cvec_init_gl_vertex_array_heap(
	t_gl_vertex_array *vals, size_t num)
{
	t_cvector_gl_vertex_array	*vec;

	vec = (t_cvector_gl_vertex_array *)malloc(
			sizeof(t_cvector_gl_vertex_array));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->capacity = num + CVEC_SIZE;
	vec->size = num;
	vec->a = (t_gl_vertex_array *)malloc(
			sizeof(t_gl_vertex_array) * vec->capacity);
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	ft_memmove(vec->a, vals, sizeof(t_gl_vertex_array) * num);
	return (vec);
}

int	cvec_extend_gl_vertex_array(t_cvector_gl_vertex_array *vec, size_t num)
{
	t_gl_vertex_array	*tmp;
	size_t				tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_SIZE;
		tmp = (t_gl_vertex_array *)ft_realloc(vec->a,
				sizeof(t_gl_vertex_array) * tmp_sz,
				sizeof(t_gl_vertex_array) * vec->capacity);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	vec->size += num;
	return (1);
}
