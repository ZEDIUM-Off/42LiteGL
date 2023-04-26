/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_vec2_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:40:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/24 13:10:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec2	cvec_replace_vec2(
	t_cvector_vec2 *vec, size_t i, t_vec2 a)
{
	t_vec2	tmp;

	tmp = vec->a[i];
	vec->a[i] = a;
	return (tmp);
}

void	cvec_erase_vec2(
	t_cvector_vec2	*vec, size_t start, size_t end)
{
	size_t	d;

	d = end - start + 1;
	ft_memmove(&vec->a[start], &vec->a[end + 1],
		(vec->size - 1 - end) * sizeof(t_vec2));
	vec->size -= d;
}

int	cvec_reserve_vec2(t_cvector_vec2 *vec, size_t size)
{
	t_vec2	*tmp;

	if (vec->capacity < size)
	{
		tmp = (t_vec2 *)ft_realloc(
				vec->a, sizeof(t_vec2) * (size + CVEC_SIZE),
				vec->capacity * sizeof(t_vec2));
		if (!tmp)
		{
			ft_assert(tmp != NULL);
			return (0);
		}
		vec->a = tmp;
		vec->capacity = size + CVEC_SIZE;
	}
	return (1);
}

t_vec2	*cvec_back_vec2(t_cvector_vec2 *vec)
{
	return (&vec->a[vec->size - 1]);
}
