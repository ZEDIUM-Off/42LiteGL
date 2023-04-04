/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_vec2_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:41:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:41:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_set_cap_vec2(t_cvector_vec2 *vec, size_t size)
{
	t_vec2	*tmp;

	if (size < vec->size)
		vec->size = size;
	tmp = (t_vec2 *)ft_realloc(vec->a, sizeof(t_vec2) * size);
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	vec->a = tmp;
	vec->capacity = size;
	return (1);
}

void	cvec_set_val_sz_vec2(t_cvector_vec2 *vec, t_vec2 val)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		vec->a[i++] = val;
	}
}

void	cvec_set_val_cap_vec2(t_cvector_vec2 *vec, t_vec2 val)
{
	size_t	i;

	i = 0;
	while (i < vec->capacity)
	{
		vec->a[i++] = val;
	}
}

void	cvec_clear_vec2(t_cvector_vec2 *vec)
{
	vec->size = 0;
}
