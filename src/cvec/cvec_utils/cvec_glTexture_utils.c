/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glTexture_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:24:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:04:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_texture	cvec_replace_gl_texture(
	t_cvector_gl_texture *vec, size_t i, t_gl_texture a)
{
	t_gl_texture	tmp;

	tmp = vec->a[i];
	vec->a[i] = a;
	return (tmp);
}

void	cvec_erase_gl_texture(
	t_cvector_gl_texture	*vec, size_t start, size_t end)
{
	size_t	d;

	d = end - start + 1;
	ft_memmove(&vec->a[start],
		&vec->a[end + 1], (vec->size - 1 - end) * sizeof(t_gl_texture));
	vec->size -= d;
}

int	cvec_reserve_gl_texture(t_cvector_gl_texture *vec, size_t size)
{
	t_gl_texture	*tmp;

	if (vec->capacity < size)
	{
		tmp = (t_gl_texture *)ft_realloc(
				vec->a, sizeof(t_gl_texture) * (size + CVEC_SZ));
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

t_gl_texture	*cvec_back_gl_texture(t_cvector_gl_texture *vec)
{
	return (&vec->a[vec->size - 1]);
}
