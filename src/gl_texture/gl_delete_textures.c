/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_delete_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:29:10 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 09:33:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_delete_textures(t_GLContext *c, t_gl_size n, t_gl_uint *textures)
{
	t_gl_enum	type;
	int			i;

	i = 0;
	while (i < n)
	{
		if (!textures[i] || textures[i] >= c->textures.size)
		{
			i++;
			continue ;
		}
		type = c->textures.a[textures[i]].type;
		if (textures[i] == c->bound_textures[type])
			c->bound_textures[type] = 0;
		if (!c->textures.a[textures[i]].user_owned)
		{
			free(c->textures.a[textures[i]].data);
			c->textures.a[textures[i]].data = NULL;
		}
		c->textures.a[textures[i]].deleted = GL_TRUE;
		i++;
	}
}
