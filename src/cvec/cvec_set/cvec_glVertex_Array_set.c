/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVertex_Array_set.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:20:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 15:55:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_set_cap_gl_vertex_array(t_cvector_gl_vertex_array *vec, size_t size)
{
	t_gl_vertex_array	*tmp;

	if (size < vec->size)
		vec->size = size;
	tmp = (t_gl_vertex_array *)ft_realloc(
			vec->a, sizeof(t_gl_vertex_array) * size);
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	vec->a = tmp;
	vec->capacity = size;
	return (1);
}

void	cvec_set_val_sz_gl_vertex_array(
	t_cvector_gl_vertex_array *vec, t_gl_vertex_array val)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		vec->a[i++] = val;
	}
}

void	cvec_set_val_cap_gl_vertex_array(
	t_cvector_gl_vertex_array *vec, t_gl_vertex_array val)
{
	size_t	i;

	i = 0;
	while (i < vec->capacity)
	{
		vec->a[i++] = val;
	}
}
