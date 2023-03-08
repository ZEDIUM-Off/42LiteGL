/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    cvec_glVector_copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:04:49 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:13:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_copyc_gl_vertex(void *dest, void *src)
{
	cvector_gl_vertex	*vec1;
	cvector_gl_vertex	*vec2;

	vec1 = (t_cvector_gl_vertex *)dest;
	vec2 = (t_cvector_gl_vertex *)src;
	vec1->a = NULL;
	vec1->size = 0;
	vec1->capacity = 0;
	return (cvec_copy_gl_vertex(vec1, vec2));
}

int	cvec_copy_gl_vertex(cvector_gl_vertex	*dest, t_cvector_gl_vertex *src)
{
	t_gl_vertex	*tmp;

	tmp = (t_gl_vertex *)ft_realloc(
			dest->a, src->capacity * sizeof(t_gl_vertex));
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	dest->a = tmp;
	ft_memmove(dest->a, src->a, src->size * sizeof(t_gl_vertex));
	dest->size = src->size;
	dest->capacity = src->capacity;
	return (1);
}
