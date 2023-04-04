/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_ivec3_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:59:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 13:00:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_insert_ivec3(t_cvector_ivec3 *vec, size_t i, t_ivec3 a)
{
	t_ivec3	*tmp;
	size_t	tmp_sz;

	if (vec->capacity > vec->size)
	{
		ft_memmove(&vec->a[i + 1], &vec->a[i],
			(vec->size - i) * sizeof(t_ivec3));
		vec->a[i] = a;
	}
	else
	{
		tmp_sz = (vec->capacity + 1) * 2;
		tmp = (t_ivec3 *)ft_realloc(vec->a, sizeof(t_ivec3) * tmp_sz);
		if (!tmp)
			return (ft_assert(tmp != NULL), 0);
		vec->a = tmp;
		ft_memmove(&vec->a[i + 1], &vec->a[i],
			(vec->size - i) * sizeof(t_ivec3));
		vec->a[i] = a;
		vec->capacity = tmp_sz;
	}
	vec->size++;
	return (1);
}

int	cvec_insert_array_ivec3(
	t_cvector_ivec3 *vec, size_t i, t_ivec3 *a, size_t num)
{
	t_ivec3	*tmp;
	size_t	tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_SIZE;
		tmp = (t_ivec3 *)ft_realloc(vec->a, sizeof(t_ivec3) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	ft_memmove(&vec->a[i + num], &vec->a[i],
		(vec->size - i) * sizeof(t_ivec3));
	ft_memmove(&vec->a[i], a, num * sizeof(t_ivec3));
	vec->size += num;
	return (1);
}
