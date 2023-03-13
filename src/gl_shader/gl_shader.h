/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_shader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:03:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 13:30:51 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_SHADER_H
# define GL_SHADER_H

# include <lite_gl.h>

void		set_interpol(
				t_gl_program	*prog, t_gl_sizei n, t_gl_enum *interpolation);
void		lgl_set_uniform(t_gl_context *c, void *uniform);
t_gl_uint	lgl_create_program(t_gl_context *c, t_gl_program prog_attr);
void		gl_use_program(t_gl_context *c, t_gl_uint program);
void		gl_delete_program(t_gl_context *c, t_gl_uint program);

t_vec4		texture_cubemap(t_gl_context *c, t_gl_uint tex, t_vec3 xyz);
t_vec4		texture_rect(t_gl_context *c, t_gl_uint tex, t_vec2 xy);
t_vec4		texture1d(t_gl_context *c, t_gl_uint tex, float x);
t_vec4		texture2d(t_gl_context *c, t_gl_uint tex, t_vec2 xy);
t_vec4		texture2d_array(t_gl_context *c, t_gl_uint tex, t_vec3 xyz);
t_vec4		texture3d(t_gl_context *c, t_gl_uint tex, t_vec3 xyz);

#endif