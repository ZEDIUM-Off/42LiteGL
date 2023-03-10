/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_delete_buffers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:02:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 15:04:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_delete_buffers(
	t_GLContext *c, t_gl_sizei n, const t_gl_uint *buffers)
{
	t_gl_enum	type;
	int			i;

	i = 0;
	while (i < n)
	{
		if (!buffers[i] || buffers[i] >= c->buffers.size)
		{
			i++;
			continue ;
		}
		type = c->buffers.a[buffers[i]].type;
		if (buffers[i] == c->bound_buffers[type])
			c->bound_buffers[type] = 0;
		if (!c->buffers.a[buffers[i]].user_owned)
			free(c->buffers.a[buffers[i]].data);
		c->buffers.a[buffers[i]].data = NULL;
		c->buffers.a[buffers[i]].deleted = GL_TRUE;
	}
}
