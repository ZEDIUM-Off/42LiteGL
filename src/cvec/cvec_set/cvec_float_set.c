/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_float_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:20:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 14:23:47 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_set_cap_float(t_cvector_float *vec, size_t size)
{
	float	*tmp;

	if (size < vec->size)
		vec->size = size;
	tmp = (float *)ft_realloc(vec->a, sizeof(float) * size);
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	vec->a = tmp;
	vec->capacity = size;
	return (1);
}

void	cvec_set_val_sz_float(t_cvector_float *vec, float val)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		vec->a[i++] = val;
	}
}

void	cvec_set_val_cap_float(t_cvector_float *vec, float val)
{
	size_t	i;

	i = 0;
	while (i < vec->capacity)
	{
		vec->a[i++] = val;
	}
}
