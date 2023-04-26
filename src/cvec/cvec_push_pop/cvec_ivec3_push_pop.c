/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_ivec3_push_pop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:42:26 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/24 12:55:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_push_ivec3(t_cvector_ivec3 *vec, t_ivec3 a)
{
	t_ivec3	*tmp;
	size_t	tmp_sz;

	if (vec->capacity > vec->size)
		vec->a[vec->size++] = a;
	else
	{
		tmp_sz = ((vec->capacity + 1) * 2);
		tmp = (t_ivec3 *)ft_realloc(vec->a, sizeof(t_ivec3) * tmp_sz,
				vec->capacity * sizeof(t_ivec3));
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

t_ivec3	cvec_pop_ivec3(t_cvector_ivec3 *vec)
{
	return (vec->a[--vec->size]);
}
