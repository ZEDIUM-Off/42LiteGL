/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_float_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:26:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/15 10:15:32 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	cvec_clear_float(t_cvector_float *vec)
{
	vec->size = 0;
}

void	cvec_free_float_heap(void *vec)
{
	t_cvector_float	*tmp;

	tmp = (t_cvector_float *)vec;
	if (!tmp)
		return ;
	free(tmp->a);
	free(tmp);
}

void	cvec_free_float(void *vec)
{
	t_cvector_float	*tmp;

	tmp = (t_cvector_float *)vec;
	free(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}
