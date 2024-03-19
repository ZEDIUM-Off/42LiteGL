/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_texture.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:19:34 by  mchenava         #+#    #+#             */
/*   Updated: 2024/03/19 17:24:14 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_TEXTURE_H
# define GL_TEXTURE_H

# include <lite_gl.h>

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
}				t_tex_im_3d_vars;

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
}				t_tex_im_2d_vars;

void			gl_bind_texture(t_gl_context *c, t_gl_enum target,
					t_gl_uint texture);
void			gl_create_textures(t_gl_context *c, t_gl_enum target,
					t_gl_sizei n, t_gl_uint *textures);
void			gl_delete_textures(t_gl_context *c, t_gl_sizei n,
					t_gl_uint *textures);
void			gl_gen_textures(t_gl_context *c, t_gl_sizei n,
					t_gl_uint *textures);
void			gl_pixel_storei(t_gl_context *c, t_gl_enum pname,
					t_gl_int param);
void			gl_tex_image_1d(t_gl_context *c, t_gl_enum target,
					t_tex_image_params *params, t_gl_void *data);
int				set_components(t_gl_context *c, int *components,
					t_gl_enum format);
void			gl_tex_image_2d(t_gl_context *c, t_gl_enum target,
					t_tex_image_params *params, t_gl_void *data);
void			gl_tex_sub_image_3d(t_gl_context *c, t_gl_enum target,
					t_tex_image_params *params, t_gl_void *data);
void			gl_texture_parameteri(t_gl_context *c, t_gl_uint texture,
					t_gl_enum pname, t_gl_int param);
void			init_tex(t_gl_texture tex, t_gl_enum target);
void			set_texparami(t_gl_context *c, t_gl_texture *tex,
					t_gl_enum pname, t_gl_int param);

#endif
