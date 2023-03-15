/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_float_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:40:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 10:25:16 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_copy_float(t_cvector_float *dest, t_cvector_float *src)
{
	float	*tmp;

	tmp = (float *)ft_realloc(dest->a, src->capacity * sizeof(float));
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	dest->a = tmp;
	ft_memmove(dest->a, src->a, src->size * sizeof(float));
	dest->size = src->size;
	dest->capacity = src->capacity;
	return (1);
}

int	cvec_copyc_float(void *dest, void *src)
{
	t_cvector_float	*vec1;
	t_cvector_float	*vec2;

	vec1 = (t_cvector_float *)dest;
	vec2 = (t_cvector_float *)src;
	vec1->a = NULL;
	vec1->size = 0;
	vec1->capacity = 0;
	return (cvec_copy_float(vec1, vec2));
}
