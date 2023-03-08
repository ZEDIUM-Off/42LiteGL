/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_push_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:47:16 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 12:52:17 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_push_float(t_cvector_float *vec, float a)
{
	float	*tmp;
	size_t	tmp_sz;

	if (vec->capacity > vec->size)
		vec->a[vec->size++] = a;
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
		vec->a[vec->size++] = a;
		vec->capacity = tmp_sz;
	}
	return (1);
}

float	cvec_pop_float(t_cvector_float *vec)
{
	return (vec->a[--vec->size]);
}
