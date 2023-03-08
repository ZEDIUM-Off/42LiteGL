/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_float_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:15:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:04:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	cvec_replace_float(t_cvector_float *vec, size_t i, float a)
{
	float	tmp;

	tmp = vec->a[i];
	vec->a[i] = a;
	return (tmp);
}

void	cvec_erase_float(t_cvector_float *vec, size_t start, size_t end)
{
	size_t	d;

	d = end - start + 1;
	ft_memmove(&vec->a[start], &vec->a[end + 1],
		(vec->size - 1 - end) * sizeof(float));
	vec->size -= d;
}

int	cvec_reserve_float(t_cvector_float *vec, size_t size)
{
	float	*tmp;

	if (vec->capacity < size)
	{
		tmp = (float *)ft_realloc(vec->a,
				sizeof(float) * (size + CVEC_SZ));
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = size + CVEC_SZ;
	}
	return (1);
}

float	*cvec_back_float(t_cvector_float *vec)
{
	return (&vec->a[vec->size - 1]);
}
