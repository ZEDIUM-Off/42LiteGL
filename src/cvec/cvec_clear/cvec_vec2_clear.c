/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_vec2_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:45:46 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:45:58 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	cvec_clear_vec2(t_cvector_vec2 *vec)
{
	vec->size = 0;
}

void	cvec_free_vec2_heap(void *vec)
{
	t_cvector_vec2	*tmp;

	tmp = (t_cvector_vec2 *)vec;
	if (!tmp)
		return ;
	free(tmp->a);
	free(tmp);
}

void	cvec_free_vec2(void *vec)
{
	t_cvector_vec2	*tmp;

	tmp = (t_cvector_vec2 *)vec;
	free(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}
