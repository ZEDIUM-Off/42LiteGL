/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_ivec3_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:45:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:45:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	cvec_clear_ivec3(t_cvector_ivec3 *vec)
{
	vec->size = 0;
}

void	cvec_free_ivec3_heap(void *vec)
{
	t_cvector_ivec3	*tmp;

	tmp = (t_cvector_ivec3 *)vec;
	if (!tmp)
		return ;
	free(tmp->a);
	free(tmp);
}

void	cvec_free_ivec3(void *vec)
{
	t_cvector_ivec3	*tmp;

	tmp = (t_cvector_ivec3 *)vec;
	free(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}
