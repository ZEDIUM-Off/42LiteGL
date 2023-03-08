/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glTexture_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:21:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:04:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_insert_gl_texture(
	t_cvector_gl_texture *vec, size_t i, t_gl_texture a)
{
	t_gl_texture	*tmp;
	size_t			tmp_sz;

	if (vec->capacity > vec->size)
	{
		ft_memmove(&vec->a[i + 1], &vec->a[i],
			(vec->size - i) * sizeof(t_gl_texture));
		vec->a[i] = a;
	}
	else
	{
		tmp_sz = (vec->capacity + 1) * 2;
		tmp = (t_gl_texture *)ft_realloc(vec->a, sizeof(t_gl_texture) * tmp_sz);
		if (!tmp)
			return (ft_assert(tmp != NULL), 0);
		vec->a = tmp;
		ft_memmove(&vec->a[i + 1], &vec->a[i],
			(vec->size - i) * sizeof(t_gl_texture));
		vec->a[i] = a;
		vec->capacity = tmp_sz;
	}
	vec->size++;
	return (1);
}

int	cvec_insert_array_gl_texture(
	t_cvector_gl_texture *vec, size_t i, t_gl_texture *a, size_t num)
{
	t_gl_texture	*tmp;
	size_t			tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_SZ;
		tmp = (t_gl_texture *)ft_realloc(
				vec->a, sizeof(t_gl_texture) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	ft_memmove(&vec->a[i + num], &vec->a[i],
		(vec->size - i) * sizeof(t_gl_texture));
	ft_memmove(&vec->a[i], a, num * sizeof(t_gl_texture));
	vec->size += num;
	return (1);
}
