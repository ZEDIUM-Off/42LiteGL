/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glTexture_push_pop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:23:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/24 12:47:57 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_push_gl_texture(t_cvector_gl_texture *vec, t_gl_texture a)
{
	t_gl_texture	*tmp;
	size_t			tmp_sz;

	if (vec->capacity > vec->size)
		vec->a[vec->size++] = a;
	else
	{
		tmp_sz = ((vec->capacity + 1) * 2);
		tmp = (t_gl_texture *)ft_realloc(vec->a, sizeof(t_gl_texture) * tmp_sz,
				vec->capacity * sizeof(t_gl_texture));
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

t_gl_texture	cvec_pop_gl_texture(t_cvector_gl_texture *vec)
{
	return (vec->a[--vec->size]);
}
