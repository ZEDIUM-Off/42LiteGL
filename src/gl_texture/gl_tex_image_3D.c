/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_tex_image_3D.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:03:42 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/25 14:21:02 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	copy_img_data_3d(
	t_gl_context *c, t_tex_image_params *params,
	t_tex_im_3d_vars *vars, t_gl_void *data)
{
	c->textures.a[vars->cur_tex].data = (t_u8 *)malloc(
			params->width * params->height * params->depth * vars->components);
	if (!c->textures.a[vars->cur_tex].data)
		return (set_err(c, GL_OUT_OF_MEMORY));
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
		return (set_err(c, GL_INVALID_ENUM));
	if (params->border)
		return (set_err(c, GL_INVALID_ENUM));
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
