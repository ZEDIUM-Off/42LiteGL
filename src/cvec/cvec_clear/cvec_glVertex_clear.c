/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVertex_clear.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:05:23 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:13:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	cvec_clear_gl_vertex(t_cvector_gl_vertex *vec)
{
	vec->size = 0;
}

void	cvec_free_gl_vertex_heap(void *vec)
{
	cvector_gl_vertex	*tmp;

	tmp = (t_cvector_gl_vertex *)vec;
	if (!tmp)
		return ;
	free(tmp->a);
	free(tmp);
}

void	cvec_free_gl_vertex(void *vec)
{
	cvector_gl_vertex	*tmp;

	tmp = (t_cvector_gl_vertex *)vec;
	free(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}
