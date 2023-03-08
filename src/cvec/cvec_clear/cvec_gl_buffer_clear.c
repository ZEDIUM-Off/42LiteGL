/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_gl_buffer_clear.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:55:15 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/05 21:18:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	cvec_clear_gl_buffer(t_cvector_gl_buffer *vec)
{
	vec->size = 0;
}

void	cvec_free_gl_buffer_heap(void *vec)
{
	t_cvector_gl_buffer	*tmp;

	tmp = (t_cvector_gl_buffer *)vec;
	if (!tmp)
		return ;
	free(tmp->a);
	free(tmp);
}

void	cvec_free_gl_buffer(void *vec)
{
	t_cvector_gl_buffer	*tmp;

	tmp = (t_cvector_gl_buffer *)vec;
	free(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}
