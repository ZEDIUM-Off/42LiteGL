/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glTexture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:25:24 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:04:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_cvector_gl_texture	*cvec_init_gl_texture_heap(
	t_gl_texture *vals, size_t num)
{
	t_cvector_gl_texture	*vec;

	vec = (t_cvector_gl_texture *)malloc(sizeof(t_cvector_gl_texture));
	if (!vec)
	{
		ft_assert(vec != NULL);
		return (NULL);
	}
	vec->capacity = num + CVEC_SZ;
	vec->size = num;
	vec->a = (t_gl_texture *)malloc(vec->capacity * sizeof(t_gl_texture));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		free(vec);
		return (NULL);
	}
	ft_memmove(vec->a, vals, sizeof(t_gl_texture) * num);
	return (vec);
}

int	cvec_gl_texture(t_cvector_gl_texture *vec, size_t size, size_t capacity)
{
	vec->size = size;
	vec->capacity = vec->size + CVEC_SZ;
	if (capacity > vec->size || (vec->size && capacity == vec->size))
		vec->capacity = capacity;
	vec->a = (t_gl_texture *)malloc(vec->capacity * sizeof(t_gl_texture));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	return (1);
}

int	cvec_init_gl_texture(
	t_cvector_gl_texture *vec, t_gl_texture *vals, size_t num)
{
	vec->capacity = num + CVEC_SZ;
	vec->size = num;
	vec->a = (t_gl_texture *)malloc(vec->capacity * sizeof(t_gl_texture));
	if (!vec->a)
	{
		ft_assert(vec->a != NULL);
		vec->size = 0;
		vec->capacity = 0;
		return (0);
	}
	ft_memmove(vec->a, vals, sizeof(t_gl_texture) * num);
	return (1);
}

int	cvec_extend_gl_texture(t_cvector_gl_texture *vec, size_t num)
{
	t_gl_texture	*tmp;
	size_t			tmp_sz;

	if (vec->capacity < vec->size + num)
	{
		tmp_sz = vec->capacity + num + CVEC_SZ;
		tmp = (t_gl_texture *)ft_realloc(vec->a, sizeof(t_gl_texture) * tmp_sz);
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	vec->size += num;
	return (1);
}
