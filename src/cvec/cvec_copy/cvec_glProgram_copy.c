/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glProgram_copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:30:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:30:59 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_copyc_gl_program(void *dest, void *src)
{
	t_cvector_gl_program	*vec1;
	t_cvector_gl_program	*vec2;

	vec1 = (t_cvector_gl_program *)dest;
	vec2 = (t_cvector_gl_program *)src;
	vec1->a = NULL;
	vec1->size = 0;
	vec1->capacity = 0;
	return (cvec_copy_gl_program(vec1, vec2));
}

int	cvec_copy_gl_program(
	t_cvector_gl_program	*dest, t_cvector_gl_program *src)
{
	t_gl_program	*tmp;

	tmp = (t_gl_program *)ft_realloc(
			dest->a, src->capacity * sizeof(t_gl_program));
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	dest->a = tmp;
	ft_memmove(dest->a, src->a, src->size * sizeof(t_gl_program));
	dest->size = src->size;
	dest->capacity = src->capacity;
	return (1);
}
