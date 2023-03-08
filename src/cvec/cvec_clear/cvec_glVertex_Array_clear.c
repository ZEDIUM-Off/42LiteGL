/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glVertex_Array_clear.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:26:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 14:51:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cvec_clear_gl_vertex_array(t_cvector_gl_vertex_array *vec)
{
	vec->size = 0;
}

void	cvec_free_gl_vertex_array_heap(void *vec)
{
	t_cvector_gl_vertex_array	*tmp;

	tmp = (t_cvector_gl_vertex_array *)vec;
	if (!tmp)
		return ;
	free(tmp->a);
	free(tmp);
}

void	cvec_free_gl_vertex_array(void *vec)
{
	t_cvector_gl_vertex_array	*tmp;

	tmp = (t_cvector_gl_vertex_array *)vec;
	free(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}
