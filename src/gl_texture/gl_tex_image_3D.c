/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_tex_image_3D.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:03:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 19:24:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

typedef struct tex_im_3d_vars
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
}	t_tex_im_3d_vars;

void	copy_img_data_3d(
	t_gl_context *c, t_tex_image_params *params,
	t_tex_im_3d_vars *vars, t_gl_void *data)
{
	c->textures.a[vars->cur_tex].data = (t_u8 *)malloc(
			params->width * params->height * params->depth * vars->components);
	if (!c->textures.a[vars->cur_tex].data)
		return ({if (!c->error) c->error = GL_OUT_OF_MEMORY;});
	vars->texdata = (t_u8 *)c->textures.a[vars->cur_tex].data;
	if (data)
	{
		if (!vars->padding_needed)
			ft_memcpy(vars->texdata, data, params->width * params->height
				* params->depth * sizeof(t_u32));
		else
		{
			vars->p = 0;
			while (vars->p < params->height * params->depth)
			{
				ft_memcpy(&vars->texdata[vars->p * vars->byte_width],
					&((t_u8 *)data)[vars->p * vars->padded_row_len],
					vars->byte_width);
				vars->p++;
			}
		}
	}
	c->textures.a[vars->cur_tex].user_owned = GL_FALSE;
}

void	gl_tex_image_3d(
	t_gl_context *c, t_gl_enum target,
	t_tex_image_params *params, t_gl_void *data)
{
	t_tex_im_3d_vars	vars;

	if (target != GL_TEXTURE_3D && target != GL_TEXTURE_2D_ARRAY)
		return ({if (!c->error) c->error = GL_INVALID_ENUM;});
	if (params->border)
		return ({if (!c->error) c->error = GL_INVALID_VALUE;});
	vars.cur_tex = c->bound_textures[target - GL_TEXTURE_UNBOUND - 1];
	c->textures.a[vars.cur_tex].w = params->width;
	c->textures.a[vars.cur_tex].h = params->height;
	c->textures.a[vars.cur_tex].d = params->depth;
	if (params->type != GL_UNSIGNED_BYTE)
		return ;
	if (!set_components(c, &vars.components, params->format))
		return ;
	vars.byte_width = vars.components * params->width;
	vars.padding_needed = vars.byte_width % c->unpack_alignment;
	vars.padded_row_len = vars.byte_width
		+ c->unpack_alignment - vars.padding_needed;
	if (!vars.padding_needed)
		vars.padded_row_len = vars.byte_width;
	free(c->textures.a[vars.cur_tex].data);
	copy_img_data_3d(c, params, &vars, data);
}
