/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:53:35 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:05:19 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

cvector_gl_vertex	*cvec_gl_vertex_heap(size_t size, size_t capacity)
{
	cvector_gl_vertex	*vec;

	vec = (t_cvector_gl_vertex *)malloc(sizeof(cvector_gl_vertex));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->size = size;
	vec->capacity = vec->size + CVEC_SZ;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (t_gl_vertex *)malloc(vec->capacity * sizeof(t_gl_vertex));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	return (vec);
}

cvector_gl_vertex	*cvec_init_gl_vertex_heap(t_gl_vertex *vals, size_t num)
{
	cvector_gl_vertex	*vec;

	vec = (t_cvector_gl_vertex *)malloc(sizeof(cvector_gl_vertex));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->capacity = num + CVEC_SZ;
	vec->size = num;
	vec->a = (t_gl_vertex *)malloc(vec->capacity * sizeof(t_gl_vertex));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	ft_memmove(vec->a, vals, sizeof(t_gl_vertex) * num);
	return (vec);
}

int	cvec_gl_vertex(t_cvector_gl_vertex *vec, size_t size, size_t capacity)
{
	vec->size = size;
	vec->capacity = vec->size + CVEC_SZ;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (t_gl_vertex *)malloc(vec->capacity * sizeof(t_gl_vertex));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	return (1);
}

int	cvec_init_gl_vertex(
	t_cvector_gl_vertex *vec, t_gl_vertex *vals, size_t num)
{
	vec->capacity = num + CVEC_SZ;
	vec->size = num;
	vec->a = (t_gl_vertex *)malloc(vec->capacity * sizeof(t_gl_vertex));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	ft_memmove(vec->a, vals, sizeof(t_gl_vertex) * num);
	return (1);
}

int	cvec_extend_gl_vertex(t_cvector_gl_vertex *vec, size_t num)
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
	vec->size += num;
	return (1);
}
