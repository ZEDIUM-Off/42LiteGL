/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_create_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:28:07 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	second_loop(
	t_gl_context *c, t_gl_enum target, t_gl_sizei *nj, t_gl_uint *textures)
{
	int	j;
	int	i;

	i = c->textures.size;
	j = nj[1];
	cvec_extend_glTexture(&c->textures, nj[0] - j);
	while (j < nj[0])
	{
		init_tex(c->textures.a[i], target);
		c->textures.a[i].deleted = GL_FALSE;
		c->textures.a[i].type = GL_TEXTURE_UNBOUND;
		textures[j++] = i++;
	}
}

void	gl_create_textures(
	t_gl_context *c, t_gl_enum target, t_gl_sizei n, t_gl_uint *textures)
{
	t_gl_sizei	j;
	int			i;

	if (target < GL_TEXTURE_1D || target >= GL_NUM_TEXTURE_TYPES)
		return (if (!c->error) c->error = GL_INVALID_ENUM);
	target -= GL_TEXTURE_UNBOUND + 1;
	j = 0;
	i = 0;
	while (i < c->textures.size && j < n)
	{
		if (c->textures.a[i].deleted)
		{
			init_tex(c->textures.a[i], target);
			textures[j++] = i;
		}
		i++;
	}
	if (j != n)
		second_loop(c, target, {n, j}, textures);
}
