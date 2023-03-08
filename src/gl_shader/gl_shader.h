/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_shader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:03:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 12:06:02 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_SHADER_H
# define GL_SHADER_H

# include <lite_gl.h>

void		set_interpol(
				t_glProgram	*prog, t_gl_sizei n, t_gl_enum *interpolation);
void		lgl_set_uniform(t_GLContext *c, void *uniform);
t_gl_uint	lgl_create_program(t_GLContext *c, t_glProgram prog_attr);
void		gl_use_program(t_GLContext *c, t_gl_uint program);
void		gl_delete_program(t_GLContext *c, t_gl_uint program);