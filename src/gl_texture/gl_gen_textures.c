/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_gen_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:21:52 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 09:28:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_gen_textures(t_GLContext *c, t_gl_size n, t_gl_uint *textures)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < c->textures.size && j < n)
	{
		if (c->textures.a[i].deleted)
		{
			c->textures.a[i].deleted = GL_FALSE;
			c->textures.a[i].type = GL_TEXTURE_UNBOUND;
			textures[j++] = i++;
		}
	}
	if (j != n)
	{
		i = c->textures.size;
		cvec_extend_gl_texture(&c->textures, n - j);
		while (j < n)
		{
			c->textures.a[i].deleted = GL_FALSE;
			c->textures.a[i].type = GL_TEXTURE_UNBOUND;
			textures[j++] = i++;
		}
	}
}
