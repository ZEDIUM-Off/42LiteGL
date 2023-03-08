/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glTexture_copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:21:02 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:21:12 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_copyc_gl_texture(void *dest, void *src)
{
	t_cvector_gl_texture	*vec1;
	t_cvector_gl_texture	*vec2;

	vec1 = (t_cvector_gl_texture *)dest;
	vec2 = (t_cvector_gl_texture *)src;
	vec1->a = NULL;
	vec1->size = 0;
	vec1->capacity = 0;
	return (cvec_copy_gl_texture(vec1, vec2));
}

int	cvec_copy_gl_texture(
	t_cvector_gl_texture	*dest, t_cvector_gl_texture *src)
{
	t_gl_texture	*tmp;

	tmp = (t_gl_texture *)ft_realloc(
			dest->a, src->capacity * sizeof(t_gl_texture));
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	dest->a = tmp;
	ft_memmove(dest->a, src->a, src->size * sizeof(t_gl_texture));
	dest->size = src->size;
	dest->capacity = src->capacity;
	return (1);
}
