/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_ivec3_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:43:40 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:44:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_copyc_ivec3(void *dest, void *src)
{
	t_cvector_ivec3	*vec1;
	t_cvector_ivec3	*vec2;

	vec1 = (t_cvector_ivec3 *)dest;
	vec2 = (t_cvector_ivec3 *)src;
	vec1->a = NULL;
	vec1->size = 0;
	vec1->capacity = 0;
	return (cvec_copy_ivec3(vec1, vec2));
}

int	cvec_copy_ivec3(t_cvector_ivec3	*dest, t_cvector_ivec3 *src)
{
	t_ivec3	*tmp;

	tmp = (t_ivec3 *)ft_realloc(
			dest->a, src->capacity * sizeof(t_ivec3));
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	dest->a = tmp;
	ft_memmove(dest->a, src->a, src->size * sizeof(t_ivec3));
	dest->size = src->size;
	dest->capacity = src->capacity;
	return (1);
}
