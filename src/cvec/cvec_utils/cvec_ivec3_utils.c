/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_ivec3_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:39:24 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/24 13:10:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_ivec3	cvec_replace_ivec3(
	t_cvector_ivec3 *vec, size_t i, t_ivec3 a)
{
	t_ivec3	tmp;

	tmp = vec->a[i];
	vec->a[i] = a;
	return (tmp);
}

void	cvec_erase_ivec3(
	t_cvector_ivec3	*vec, size_t start, size_t end)
{
	size_t	d;

	d = end - start + 1;
	ft_memmove(&vec->a[start], &vec->a[end + 1],
		(vec->size - 1 - end) * sizeof(t_ivec3));
	vec->size -= d;
}

int	cvec_reserve_ivec3(t_cvector_ivec3 *vec, size_t size)
{
	t_ivec3	*tmp;

	if (vec->capacity < size)
	{
		tmp = (t_ivec3 *)ft_realloc(
				vec->a, sizeof(t_ivec3) * (size + CVEC_SIZE),
				vec->capacity * sizeof(t_ivec3));
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = size + CVEC_SIZE;
	}
	return (1);
}

t_ivec3	*cvec_back_ivec3(t_cvector_ivec3 *vec)
{
	return (&vec->a[vec->size - 1]);
}
