/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:37:08 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 12:08:41 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_vertex	**new_vertex2(t_gl_vertex *v1, t_gl_vertex *v2)
{
	t_gl_vertex	**new;

	new = (t_gl_vertex **)malloc(sizeof(t_gl_vertex *) * 2);
	new[0] = v1;
	new[1] = v2;
	return (new);
}

t_gl_vertex	**new_vertex3(t_gl_vertex *v1, t_gl_vertex *v2, t_gl_vertex *v3)
{
	t_gl_vertex	**new;

	new = (t_gl_vertex **)malloc(sizeof(t_gl_vertex *) * 3);
	new[0] = v1;
	new[1] = v2;
	new[2] = v3;
	return (new);
}

t_gl_vertex	**new_vertex4(t_gl_vertex *v1, t_gl_vertex *v2,
	t_gl_vertex *v3, t_gl_vertex *v4)
{
	t_gl_vertex	**new;

	new = (t_gl_vertex **)malloc(sizeof(t_gl_vertex *) * 4);
	new[0] = v1;
	new[1] = v2;
	new[2] = v3;
	new[3] = v4;
	return (new);
}
