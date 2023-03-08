/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVerxtex_push_pop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:02:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:13:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_push_gl_vertex(t_cvector_gl_vertex *vec, t_gl_vertex a)
{
	t_gl_vertex	*tmp;
	size_t		tmp_sz;

	if (vec->capacity > vec->size)
		vec->a[vec->size++] = a;
	else
	{
		tmp_sz = ((vec->capacity + 1) * 2);
		tmp = (t_gl_vertex *)ft_realloc(vec->a, sizeof(t_gl_vertex) * tmp_sz);
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

t_gl_vertex	cvec_pop_gl_vertex(t_cvector_gl_vertex *vec)
{
	return (vec->a[--vec->size]);
}
