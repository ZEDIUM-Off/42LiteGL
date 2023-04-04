/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_vec3_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:18:28 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:31:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec3	cvec_replace_vec3(t_cvector_vec3 *vec, size_t i, t_vec3 a)
{
	t_vec3	old;

	old = vec->a[i];
	vec->a[i] = a;
	return (old);
}

void	cvec_erase_vec3(t_cvector_vec3 *vec, size_t start, size_t end)
{
	size_t	d;

	d = end - start + 1;
	ft_memmove(&vec->a[start], &vec->a[end + 1],
		sizeof(t_vec3) * (vec->size - end - 1));
	vec->size -= d;
}

int	cvec_reserve_vec3(t_cvector_vec3 *vec, size_t size)
{
	t_vec3	*new;

	if (vec->capacity < size)
	{
		new = (t_vec3 *)ft_realloc(vec->a, sizeof(t_vec3) * (size + CVEC_SIZE));
		if (!new)
		{
			ft_assert(new != NULL);
			return (0);
		}
		vec->a = new;
		vec->capacity = size + CVEC_SIZE;
	}
	return (1);
}

t_vec3	*cvec_back_vec3(t_cvector_vec3 *vec)
{
	return (&vec->a[vec->size - 1]);
}
