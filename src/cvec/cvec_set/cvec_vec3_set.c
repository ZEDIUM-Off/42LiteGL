/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_vec3_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:31:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:32:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	cvec_set_cap_vec3(t_cvector_vec3 *vec, size_t size)
{
	t_vec3	*tmp;

	if (size < vec->size)
		vec->size = size;
	tmp = (t_vec3 *)ft_realloc(vec->a, sizeof(t_vec3) * size);
	if (!tmp)
	{
		ft_assert(tmp != NULL);
		return (0);
	}
	vec->a = tmp;
	vec->capacity = size;
	return (1);
}

void	cvec_set_val_sz_vec3(t_cvector_vec3 *vec, t_vec3 val)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		vec->a[i++] = val;
	}
}

void	cvec_set_val_cap_vec3(t_cvector_vec3 *vec, t_vec3 val)
{
	size_t	i;

	i = 0;
	while (i < vec->capacity)
	{
		vec->a[i++] = val;
	}
}

void	cvec_clear_vec3(t_cvector_vec3 *vec)
{
	vec->size = 0;
}
