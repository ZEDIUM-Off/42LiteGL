/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_vec2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:36:52 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/24 13:12:13 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_cvector_vec2	*cvec_vec2_heap(size_t size, size_t capacity)
{
	t_cvector_vec2	*vec;

	vec = (t_cvector_vec2 *)malloc(sizeof(t_cvector_vec2));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->size = size;
	vec->capacity = vec->size + CVEC_SIZE;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (t_vec2 *)malloc(vec->capacity * sizeof(t_vec2));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	return (vec);
}

t_cvector_vec2	*cvec_init_vec2_heap(t_vec2 *vals, size_t num)
{
	t_cvector_vec2	*vec;

	vec = (t_cvector_vec2 *)malloc(sizeof(t_cvector_vec2));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->capacity = num + CVEC_SIZE;
	vec->size = num;
	vec->a = (t_vec2 *)malloc(vec->capacity * sizeof(t_vec2));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	ft_memmove(vec->a, vals, sizeof(t_vec2) * num);
	return (vec);
}

int	cvec_vec2(t_cvector_vec2 *vec, size_t size, size_t capacity)
{
	vec->size = size;
	vec->capacity = vec->size + CVEC_SIZE;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (t_vec2 *)malloc(vec->capacity * sizeof(t_vec2));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	return (1);
}

int	cvec_init_vec2(
	t_cvector_vec2 *vec, t_vec2 *vals, size_t num)
{
	vec->capacity = num + CVEC_SIZE;
	vec->size = num;
	vec->a = (t_vec2 *)malloc(vec->capacity * sizeof(t_vec2));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	ft_memmove(vec->a, vals, sizeof(t_vec2) * num);
	return (1);
}

int	cvec_extend_vec2(t_cvector_vec2 *vec, size_t num)
{
	t_vec2	*tmp;
	size_t	tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_SIZE;
		tmp = (t_vec2 *)ft_realloc(vec->a, sizeof(t_vec2) * tmp_sz,
				sizeof(t_vec2) * vec->capacity);
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
