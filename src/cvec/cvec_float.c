/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:25:43 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 10:36:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_float(t_cvector_float *vec, size_t size, size_t capacity)
{
	vec->size = size;
	vec->capacity = vec->size + CVEC_SIZE;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (float *)malloc(sizeof(float) * vec->capacity);
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	return (1);
}

int	cvec_init_float(t_cvector_float *vec, float *vals, size_t num)
{
	vec->size = num;
	vec->capacity = vec->size + CVEC_SIZE;
	vec->a = (float *)malloc(sizeof(float) * vec->capacity);
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	ft_memmove(vec->a, vals, sizeof(float) * num);
	return (1);
}

t_cvector_float	*cvec_float_heap(size_t size, size_t capacity)
{
	t_cvector_float	*vec;

	vec = (t_cvector_float *)malloc(sizeof(t_cvector_float));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->size = size;
	vec->capacity = vec->size + CVEC_SIZE;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (float *)malloc(sizeof(float) * vec->capacity);
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	return (vec);
}

t_cvector_float	*cvec_init_float_heap(float *vals, size_t num)
{
	t_cvector_float	*vec;

	vec = (t_cvector_float *)malloc(sizeof(t_cvector_float));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->capacity = num + CVEC_SIZE;
	vec->size = num;
	vec->a = (float *)malloc(sizeof(float) * vec->capacity);
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	ft_memmove(vec->a, vals, sizeof(float) * num);
	return (vec);
}

int	cvec_extend_float(t_cvector_float *vec, size_t num)
{
	float	*tmp;
	size_t	tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_SIZE;
		tmp = (float *)ft_realloc(vec->a, sizeof(float) * tmp_sz);
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
