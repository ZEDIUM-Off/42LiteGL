/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVextex_Array_copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:40:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 15:48:43 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_copy_gl_vertex_array(
	t_cvector_gl_vertex_array *dest, t_cvector_gl_vertex_array *src)
{
	t_gl_vertex_array	*tmp;

	tmp = (t_gl_vertex_array *)malloc(
			dest->a, src->capacity * sizeof(t_gl_vertex_array));
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	dest->a = tmp;
	ft_memove(dest->a, src->a, src->size * sizeof(t_gl_vertex_array));
	dest->size = src->size;
	dest->capacity = src->capacity;
	return (1);
}

int	cvec_copyc_gl_vertex_array(void *dest, void *src)
{
	t_cvec_gl_vertex_array	*vec1;
	t_cvec_gl_vertex_array	*vec2;

	vec1 = (t_cvec_gl_vertex_array *)dest;
	vec2 = (t_cvec_gl_vertex_array *)src;
	vec1->a = NULL;
	vec1->size = 0;
	vec1->capacity = 0;
	return (cvec_copy_gl_vertex_array(vec1, vec2));
}
