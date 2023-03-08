/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVertex_Array_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:15:20 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:04:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_vertex_array	cvec_replace_gl_vertex_array(
	t_cvector_gl_vertex_array *vec, size_t i, t_gl_vertex_array a)
{
	t_gl_vertex_array	tmp;

	tmp = vec->a[i];
	vec->a[i] = a;
	return (tmp);
}

void	cvec_erase_gl_vertex_array(
	t_cvector_gl_vertex_array *vec, size_t start, size_t end)
{
	size_t	d;

	d = end - start + 1;
	ft_memmove(&vec->a[start], &vec->a[end + 1],
		(vec->size - 1 - end) * sizeof(t_gl_vertex_array));
	vec->size -= d;
}

int	cvec_reserve_gl_vertex_array(t_cvector_gl_vertex_array *vec, size_t size)
{
	t_gl_vertex_array	*tmp;

	if (vec->capacity < size)
	{
		tmp = (t_gl_vertex_array *)ft_realloc(vec->a,
				sizeof(t_gl_vertex_array) * (size + CVEC_SZ));
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

float	*cvec_back_gl_vertex_array(t_cvector_gl_vertex_array *vec)
{
	return (&vec->a[vec->size - 1]);
}
