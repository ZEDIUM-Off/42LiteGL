/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_gl_buffer_push_pop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:47:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/05 21:18:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_push_gl_buffer(t_cvector_gl_buffer *vec, t_gl_buffer a)
{
	t_gl_buffer	*tmp;
	size_t		tmp_sz;

	if (vec->capacity > vec->size)
		vec->a[vec->size++] = a;
	else
	{
		tmp_sz = ((vec->capacity + 1) * 2);
		tmp = (t_gl_buffer *)ft_realloc(vec->a, sizeof(t_gl_buffer) * tmp_sz);
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

t_gl_buffer	cvec_pop_gl_buffer(t_cvector_gl_buffer *vec)
{
	return (vec->a[--vec->size]);
}
