/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glProgram_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:33:32 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:33:55 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_set_cap_gl_program(t_cvector_gl_program *vec, size_t size)
{
	t_gl_program	*tmp;

	if (size < vec->size)
		vec->size = size;
	tmp = (t_gl_program *)ft_realloc(vec->a, sizeof(t_gl_program) * size);
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	vec->a = tmp;
	vec->capacity = size;
	return (1);
}

void	cvec_set_val_sz_gl_program(t_cvector_gl_program *vec, t_gl_program val)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		vec->a[i++] = val;
	}
}

void	cvec_set_val_cap_gl_program(t_cvector_gl_program *vec, t_gl_program val)
{
	size_t	i;

	i = 0;
	while (i < vec->capacity)
	{
		vec->a[i++] = val;
	}
}
