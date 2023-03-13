/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_getters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:06:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 16:03:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_GETTERS_H
# define GL_GETTERS_H

# include <lite_gl.h>

void			gl_get_booleanv(t_gl_context *c, t_gl_enum pname,
					t_gl_boolean *params);
t_gl_enum		gl_get_error(t_gl_context *c);
void			gl_get_floatv(t_gl_context *c, t_gl_enum pname,
					t_gl_float *params);
void			gl_get_integerv(t_gl_context *c, t_gl_enum pname,
					t_gl_int *params);
char			*gl_get_string(t_gl_context *c, t_gl_enum name);
t_gl_boolean	gl_is_enable(t_gl_context *c, t_gl_enum cap);
void			lgl_get_buffer_data(
					t_gl_context *c, t_gl_uint buffer, t_gl_void **data);

#endif