/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:55:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 14:12:43 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_insert_float(t_cvector_float *vec, size_t i, float a)
{
	float	*tmp;
	size_t	tmp_sz;

	if (vec->capacity > vec->size)
	{
		ft_memmove(&vec->a[i + 1], vec->a[i], sizeof(float) * (vec->size - i));
		vec->a[i] = a;
	}
	else
	{
		tmp_sz = (vec->capacity + 1) * 2;
		tmp = (float *)ft_realloc(vec->a, sizeof(float) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		ft_memmove(&vec->a[i + 1], &vec->a[i], sizeof(float) * (vec->size - i));
		vec->a[i] = a;
		vec->capacity = tmp_sz;
	}
	vec->size++;
	return (1);
}

int	cvec_insert_array_float(t_cvector_float *vec, size_t i, float *a, size_t n)
{
	float	*tmp;
	size_t	tmp_sz;

	if (vec->capacity < vec->size + n)
	{
		tmp_sz = vec->capacity + n + CVEC_FLOAT_SIZE;
		tmp = (float *)ft_realloc(vec->a, sizeof(float) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	ft_memmove(&vec->a[i + n], &vec->a[i], sizeof(float) * (vec->size - i));
	ft_memmove(&vec->a[i], a, sizeof(float) * n);
	vec->size += n;
	return (1);
}
