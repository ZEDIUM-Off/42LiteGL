/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_gl_buffer_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:54:53 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/05 21:18:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_set_cap_gl_buffer(t_cvector_gl_buffer *vec, size_t size)
{
	t_gl_buffer	*tmp;

	if (size < vec->size)
		vec->size = size;
	tmp = (t_gl_buffer *)ft_realloc(vec->a, sizeof(t_gl_buffer) * size);
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	vec->a = tmp;
	vec->capacity = size;
	return (1);
}

void	cvec_set_val_sz_gl_buffer(t_cvector_gl_buffer *vec, t_gl_buffer val)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		vec->a[i++] = val;
	}
}

void	cvec_set_val_cap_gl_buffer(t_cvector_gl_buffer *vec, t_gl_buffer val)
{
	size_t	i;

	i = 0;
	while (i < vec->capacity)
	{
		vec->a[i++] = val;
	}
}
