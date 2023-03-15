/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVertex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:56:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 10:36:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_vertex	cvec_replace_gl_vertex(
	t_cvector_gl_vertex *vec, size_t i, t_gl_vertex a)
{
	t_gl_vertex	tmp;

	tmp = vec->a[i];
	vec->a[i] = a;
	return (tmp);
}

void	cvec_erase_gl_vertex(
	t_cvector_gl_vertex	*vec, size_t start, size_t end)
{
	size_t	d;

	d = end - start + 1;
	ft_memmove(&vec->a[start], &vec->a[end + 1],
		(vec->size - 1 - end) * sizeof(t_gl_vertex));
	vec->size -= d;
}

int	cvec_reserve_gl_vertex(t_cvector_gl_vertex *vec, size_t size)
{
	t_gl_vertex	*tmp;

	if (vec->capacity < size)
	{
		tmp = (t_gl_vertex *)ft_realloc(
				vec->a, sizeof(t_gl_vertex) * (size + CVEC_SIZE));
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = size + CVEC_SIZE;
	}
	return (1);
}

t_gl_vertex	*cvec_back_gl_vertex(t_cvector_gl_vertex *vec)
{
	return (&vec->a[vec->size - 1]);
}
