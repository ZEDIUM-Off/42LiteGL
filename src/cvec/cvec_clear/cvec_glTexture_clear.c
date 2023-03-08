/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_glTexture_clear.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:20:24 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:20:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	cvec_clear_gl_texture(t_cvector_gl_texture *vec)
{
	vec->size = 0;
}

void	cvec_free_gl_texture_heap(void *vec)
{
	t_cvector_gl_texture	*tmp;

	tmp = (t_cvector_gl_texture *)vec;
	if (!tmp)
		return ;
	free(tmp->a);
	free(tmp);
}

void	cvec_free_gl_texture(void *vec)
{
	t_cvector_gl_texture	*tmp;

	tmp = (t_cvector_gl_texture *)vec;
	free(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}
