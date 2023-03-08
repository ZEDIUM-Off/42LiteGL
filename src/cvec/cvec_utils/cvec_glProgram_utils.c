/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glProgram_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:34:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:04:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_program	cvec_replace_gl_program(
	t_cvector_gl_program *vec, size_t i, t_gl_program a)
{
	t_gl_program	tmp;

	tmp = vec->a[i];
	vec->a[i] = a;
	return (tmp);
}

void	cvec_erase_gl_program(
	t_cvector_gl_program	*vec, size_t start, size_t end)
{
	size_t	d;

	d = end - start + 1;
	ft_memmove(&vec->a[start], &vec->a[end + 1],
		(vec->size - 1 - end) * sizeof(t_gl_program));
	vec->size -= d;
}

int	cvec_reserve_gl_program(t_cvector_gl_program *vec, size_t size)
{
	t_gl_program	*tmp;

	if (vec->capacity < size)
	{
		tmp = (t_gl_program *)ft_realloc(
				vec->a, sizeof(t_gl_program) * (size + CVEC_SZ));
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

t_gl_program	*cvec_back_gl_program(t_cvector_gl_program *vec)
{
	return (&vec->a[vec->size - 1]);
}
