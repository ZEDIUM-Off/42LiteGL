/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_vec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:30:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:37:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_cvector_vec3	*cvec_vec3_heap(size_t size, size_t capacity)
{
	t_cvector_vec3	*vec;

	vec = (t_cvector_vec3 *)malloc(sizeof(t_cvector_vec3));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->size = size;
	vec->capacity = vec->size + CVEC_SIZE;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (t_vec3 *)malloc(vec->capacity * sizeof(t_vec3));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	return (vec);
}

t_cvector_vec3	*cvec_init_vec3_heap(t_vec3 *vals, size_t num)
{
	t_cvector_vec3	*vec;

	vec = (t_cvector_vec3 *)malloc(sizeof(t_cvector_vec3));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->capacity = num + CVEC_SIZE;
	vec->size = num;
	vec->a = (t_vec3 *)malloc(vec->capacity * sizeof(t_vec3));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	ft_memmove(vec->a, vals, sizeof(t_vec3) * num);
	return (vec);
}

int	cvec_vec3(t_cvector_vec3 *vec, size_t size, size_t capacity)
{
	vec->size = size;
	vec->capacity = vec->size + CVEC_SIZE;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (t_vec3 *)malloc(vec->capacity * sizeof(t_vec3));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	return (1);
}

int	cvec_init_vec3(
	t_cvector_vec3 *vec, t_vec3 *vals, size_t num)
{
	vec->capacity = num + CVEC_SIZE;
	vec->size = num;
	vec->a = (t_vec3 *)malloc(vec->capacity * sizeof(t_vec3));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	ft_memmove(vec->a, vals, sizeof(t_vec3) * num);
	return (1);
}

int	cvec_extend_vec3(t_cvector_vec3 *vec, size_t num)
{
	t_vec3	*tmp;
	size_t	tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_SIZE;
		tmp = (t_vec3 *)ft_realloc(vec->a, sizeof(t_vec3) * tmp_sz);
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
