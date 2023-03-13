/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:54:48 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 14:58:58 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	free_cvec(t_gl_context *c)
{
	cvec_free_gl_vertex_array(&c->vertex_arrays);
	cvec_free_gl_buffer(&c->buffers);
	cvec_free_gl_program(&c->programs);
	cvec_free_gl_texture(&c->textures);
	cvec_free_gl_vertex(&c->glverts);
	cvec_free_float(&c->vs_output.output_buf);
}

void	free_gl_context(t_gl_context *c)
{
	size_t	i;

	free(c->zbuf.buf);
	free(c->stencil_buf.buf);
	if (!c->user_alloced_backbuf)
		free(c->back_buffer.buf);
	i = 0;
	while (i < c->buffers.size)
	{
		if (!c->buffers.a[i].user_owned)
			free(c->buffers.a[i].data);
		i++;
	}
	i = 0;
	while (i < c->textures.size)
	{
		if (!c->textures.a[i].user_owned)
			free(c->textures.a[i].data);
		i++;
	}
	free_cvec(c);
}
