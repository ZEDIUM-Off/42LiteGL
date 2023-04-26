/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_vec2_push_pop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:42:57 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/24 12:48:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_push_vec2(t_cvector_vec2 *vec, t_vec2 a)
{
	t_vec2	*tmp;
	size_t	tmp_sz;

	if (vec->capacity > vec->size)
		vec->a[vec->size++] = a;
	else
	{
		tmp_sz = ((vec->capacity + 1) * 2);
		tmp = (t_vec2 *)ft_realloc(vec->a, sizeof(t_vec2) * tmp_sz,
				vec->capacity * sizeof(t_vec2));
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

t_vec2	cvec_pop_vec2(t_cvector_vec2 *vec)
{
	return (vec->a[--vec->size]);
}
