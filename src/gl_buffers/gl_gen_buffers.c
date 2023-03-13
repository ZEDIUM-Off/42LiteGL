/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_gen_buffers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:01:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 14:13:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_gen_buffers(t_gl_context *c, t_gl_sizei n, t_gl_uint *buffers)
{
	int			j;
	size_t		i;

	j = 0;
	i = 1;
	while (i < c->buffers.size && j < n)
	{
		if (c->buffers.a[i].deleted)
		{
			c->buffers.a[i].deleted = GL_FALSE;
			buffers[j++] = i;
		}
		i++;
	}
	if (j != n)
	{
		cvec_extend_gl_buffer(&c->buffers, n - j);
		i = c->buffers.size;
		while (j < n)
		{
			c->buffers.a[i].data = NULL;
			c->buffers.a[i].deleted = GL_FALSE;
			buffers[j++] = i++;
		}
	}
}

void	gl_create_buffers(t_gl_context *c, t_gl_sizei n, t_gl_uint *buffers)
{
	gl_gen_buffers(c, n, buffers);
}
