/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_shader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:03:12 by  mchenava         #+#    #+#             */
/*   Updated: 2024/03/19 17:27:53 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_SHADER_H
# define GL_SHADER_H

# include <lite_gl.h>

typedef struct texture1d_vars
{
	int				i[2];
	t_gl_texture	*t;
	t_color			*color;
	double			alpha;
	double			tmp;
}					t_texture1d_vars;

typedef struct texture2d_vars
{
	int				i[2];
	int				j[2];
	t_gl_texture	*t;
	t_color			*color;
	double			alpha;
	double			beta;
	double			tmp;
	double			xw;
	double			yh;
	int				plane;
	int				p;
	float			mag[3];
	float			s;
	float			t1;
	float			max;
}					t_texture2d_vars;

typedef struct texture3d_vars
{
	int				i[2];
	int				j[2];
	int				k[2];
	t_gl_texture	*t;
	t_color			*color;
	double			alpha;
	double			beta;
	double			gamma;
	double			tmp;
	double			xw;
	double			yh;
	double			zd;
	int				plane;
}					t_texture3d_vars;

typedef struct texture_rect_vars
{
	int				i[2];
	int				j[2];
	t_gl_texture	*t;
	t_color			*color;
	double			alpha;
	double			beta;
	double			tmp;
	double			xw;
	double			yh;
}					t_texture_rect_vars;

void				set_interpol(t_gl_program *prog, t_gl_sizei n,
						t_gl_enum *interpolation);
void				lgl_set_uniform(t_gl_context *c, void *uniform);
t_gl_uint			lgl_create_program(t_gl_context *c, t_gl_program prog_attr,
						t_gl_enum *tmp_interpolation);
void				gl_use_program(t_gl_context *c, t_gl_uint program);
void				gl_delete_program(t_gl_context *c, t_gl_uint program);

t_vec4				texture_cubemap(t_gl_context *c, t_gl_uint tex, t_vec3 xyz);
t_vec4				texture_rect(t_gl_context *c, t_gl_uint tex, t_vec2 xy);
t_vec4				texture1d(t_gl_context *c, t_gl_uint tex, float x);
t_vec4				texture2d(t_gl_context *c, t_gl_uint tex, t_vec2 xy);
t_vec4				texture2d_array(t_gl_context *c, t_gl_uint tex, t_vec3 xyz);
t_vec4				texture3d(t_gl_context *c, t_gl_uint tex, t_vec3 xyz);

#endif
