/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_vec2_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:44:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:44:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_copyc_vec2(void *dest, void *src)
{
	t_cvector_vec2	*vec1;
	t_cvector_vec2	*vec2;

	vec1 = (t_cvector_vec2 *)dest;
	vec2 = (t_cvector_vec2 *)src;
	vec1->a = NULL;
	vec1->size = 0;
	vec1->capacity = 0;
	return (cvec_copy_vec2(vec1, vec2));
}

int	cvec_copy_vec2(t_cvector_vec2	*dest, t_cvector_vec2 *src)
{
	t_vec2	*tmp;

	tmp = (t_vec2 *)ft_realloc(
			dest->a, src->capacity * sizeof(t_vec2));
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	dest->a = tmp;
	ft_memmove(dest->a, src->a, src->size * sizeof(t_vec2));
	dest->size = src->size;
	dest->capacity = src->capacity;
	return (1);
}
