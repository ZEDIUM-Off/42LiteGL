/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_vec3_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:34:07 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/24 12:46:44 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_insert_vec3(t_cvector_vec3 *vec, size_t i, t_vec3 a)
{
	t_vec3	*tmp;
	size_t	tmp_sz;

	if (vec->capacity > vec->size)
	{
		ft_memmove(&vec->a[i + 1], &vec->a[i],
			(vec->size - i) * sizeof(t_vec3));
		vec->a[i] = a;
	}
	else
	{
		tmp_sz = (vec->capacity + 1) * 2;
		tmp = (t_vec3 *)ft_realloc(vec->a, sizeof(t_vec3) * tmp_sz,
				vec->capacity * sizeof(t_vec3));
		if (!tmp)
			return (ft_assert(tmp != NULL), 0);
		vec->a = tmp;
		ft_memmove(&vec->a[i + 1], &vec->a[i],
			(vec->size - i) * sizeof(t_vec3));
		vec->a[i] = a;
		vec->capacity = tmp_sz;
	}
	vec->size++;
	return (1);
}

int	cvec_insert_array_vec3(
	t_cvector_vec3 *vec, size_t i, t_vec3 *a, size_t num)
{
	t_vec3	*tmp;
	size_t	tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_SIZE;
		tmp = (t_vec3 *)ft_realloc(vec->a, sizeof(t_vec3) * tmp_sz,
				vec->capacity * sizeof(t_vec3));
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	ft_memmove(&vec->a[i + num], &vec->a[i],
		(vec->size - i) * sizeof(t_vec3));
	ft_memmove(&vec->a[i], a, num * sizeof(t_vec3));
	vec->size += num;
	return (1);
}
