/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glProgram_clear.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:29:44 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:30:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	cvec_clear_gl_program(t_cvector_gl_program *vec)
{
	vec->size = 0;
}

void	cvec_free_gl_program_heap(void *vec)
{
	t_cvector_gl_program	*tmp;

	tmp = (t_cvector_gl_program *)vec;
	if (!tmp)
		return ;
	free(tmp->a);
	free(tmp);
}

void	cvec_free_gl_program(void *vec)
{
	t_cvector_gl_program	*tmp;

	tmp = (t_cvector_gl_program *)vec;
	free(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}
