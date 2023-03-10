/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_tex_image_2D.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:40:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 14:22:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

typedef struct tex_im_2d_vars
{
	int			cur_tex;
	int			byte_width;
	int			padding_needed;
	int			padded_row_len;
	int			mem_size;
	int			components;
	int			p;
	t_gl_enum	target;
	t_u8		*texdata;
}	t_tex_im_2d_vars;

int	test_target_border_type(
	t_GLContext *c, t_gl_enum target, t_gl_enum border, t_gl_enum type)
{
	if (target != GL_TEXTURE_2D && target != GL_TEXTURE_RECTANGLE
		&& target != GL_TEXTURE_CUBE_MAP_POSITIVE_X
		&& target != GL_TEXTURE_CUBE_MAP_NEGATIVE_X
		&& target != GL_TEXTURE_CUBE_MAP_POSITIVE_Y
		&& target != GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
		&& target != GL_TEXTURE_CUBE_MAP_POSITIVE_Z
		&& target != GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return (0);
	}
	if (border)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return (0);
	}
	if (type != GL_UNSIGNED_BYTE)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return (0);
	}
	return (1);
}

void	copy_img_data_rec(
	t_GLContext *c, t_tex_image_params *params,
	t_tex_im_2d_vars *vars, t_gl_void *data)
{
	int	i;

	vars->cur_tex = c->bound_textures[vars->target - GL_TEXTURE_UNBOUND - 1];
	c->textures.a[vars->cur_tex].w = params->width;
	c->textures.a[vars->cur_tex].h = params->height;
	free(c->textures.a[vars->cur_tex].data);
	c->textures.a[vars->cur_tex].data = (t_u8 *)malloc(
			params->height * vars->byte_width);
	if (!c->textures.a[vars->cur_tex].data)
		return (if (!c->error) c->error = GL_OUT_OF_MEMORY);
	i = 0;
	if (data)
	{
		if (!vars->padding_needed)
			ft_memcpy(c->textures.a[vars->cur_tex].data,
				data, params->height * vars->byte_width);
		else
			while (i++ < params->height)
				ft_memcpy(
					&c->textures.a[vars->cur_tex].data[i * vars->byte_width],
					&((t_u8 *)data)[i * vars->padded_row_len],
					vars->byte_width);
	}
	c->textures.a[vars->cur_tex].user_owned = GL_FALSE;
}

void	copy_loop(
	t_GLContext *c, t_tex_image_params *params,
	t_tex_im_2d_vars *vars, t_gl_void *data)
{
	int	i;

	i = 0;
	while (i < params->height)
	{
		ft_memcpy(
			&vars->texdata[vars->p * vars->target + i * vars->byte_width],
			&((t_u8 *)data)[i * vars->padded_row_len], vars->byte_width);
		i++;
	}
}

void	copy_img_data_cube(
	t_GLContext *c, t_tex_image_params *params,
	t_tex_im_2d_vars *vars, t_gl_void *data)
{
	if (!c->textures.a[vars->cur_tex].w)
		free(c->textures.a[vars->cur_tex].data);
	if (params->width != params->height)
		return (if (!c->error) c->error = GL_INVALID_VALUE);
	vars->mem_size = params->width * params->height * 6 * vars->components;
	if (c->textures.a[vars->cur_tex].w == 0)
	{
		c->textures.a[vars->cur_tex].w = params->width;
		c->textures.a[vars->cur_tex].h = params->width;
		c->textures.a[vars->cur_tex].data = (t_u8 *)malloc(vars->mem_size);
		if (!c->textures.a[vars->cur_tex].data)
			return (if (!c->error) c->error = GL_OUT_OF_MEMORY);
	}
	else if (c->textures.a[vars->cur_tex].w != params->width)
		return (if (!c->error) c->error = GL_INVALID_VALUE);
	if (data)
	{
		if (!vars->padding_needed)
			ft_memcpy(&vars->texdata[vars->p * vars->target],
				data, params->height * vars->byte_width);
		else
			copy_loop(c, params, vars, data);
	}
}

void	gl_tex_image_2d(
	t_GLContext *c, t_gl_enum target,
	t_tex_image_params *params, t_gl_void *data)
{
	t_tex_im_2d_vars	vars;

	if (!test_target_border_type(c, target, params->border, params->type))
		return ;
	if (!set_components(c, &vars.components, params->format))
		return ;
	vars.byte_width = vars.components * params->width;
	vars.padding_needed = vars.byte_width % c->unpack_alignment;
	vars.padded_row_len = vars.byte_width
		+ c->unpack_alignment - vars.padding_needed;
	vars.target = target;
	if (!vars.padding_needed)
		vars.padded_row_len = vars.byte_width;
	if (target == GL_TEXTURE_2D || target == GL_TEXTURE_RECTANGLE)
		copy_img_data_rec(c, params, &vars, data);
	else
	{
		vars.cur_tex = c->bound_textures[
			GL_TEXTURE_CUBE_MAP - GL_TEXTURE_UNBOUND - 1];
		vars.target = target - GL_TEXTURE_CUBE_MAP_POSITIVE_X;
		vars.p = params->height * vars.byte_width;
		vars.texdata = c->textures.a[vars.cur_tex].data;
		copy_img_data_cube(c, params, &vars, data);
	}
}
