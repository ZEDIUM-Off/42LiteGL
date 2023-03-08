/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glProgram_push_pop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:32:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:33:13 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_push_gl_program(t_cvector_gl_program *vec, t_gl_program a)
{
	t_gl_program	*tmp;
	size_t			tmp_sz;

	if (vec->capacity > vec->size)
		vec->a[vec->size++] = a;
	else
	{
		tmp_sz = ((vec->capacity + 1) * 2);
		tmp = (t_gl_program *)ft_realloc(
				vec->a, sizeof(t_gl_program) * tmp_sz);
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

t_gl_program	cvec_pop_gl_program(t_cvector_gl_program *vec)
{
	return (vec->a[--vec->size]);
}
