/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_delete_vertex_arrays.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:56:43 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 20:38:24 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_delete_vertex_arrays(
	t_gl_context *c, t_gl_sizei n, t_gl_uint *arrays)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!arrays[i] || arrays[i] >= c->vertex_arrays.size)
		{
			i++;
			continue ;
		}
		if (arrays[i] == c->cur_vertex_array)
		{
			ft_memcpy(&c->vertex_arrays.a[0], &c->vertex_arrays.a[arrays[i]],
				sizeof(t_gl_vertex_array));
			c->cur_vertex_array = 0;
		}
		c->vertex_arrays.a[arrays[i]].deleted = GL_TRUE;
		i++;
	}
}
