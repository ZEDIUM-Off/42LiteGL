/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:07:59 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 14:36:47 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_BUFFER_H
# define GL_BUFFER_H

# include <lite_gl.h>
# include "../types/gl_struct.h"

void	gl_buffer_data(t_gl_context *c,
			t_gl_enum target, t_gl_sizei size, const t_gl_void *data);
void	gl_bind_buffer(t_gl_context *c, t_gl_enum target, t_gl_uint buffer);
void	gl_gen_buffers(t_gl_context *c, t_gl_sizei n, t_gl_uint *buffers);
void	gl_buffer_sub_data(
			t_gl_context *c, t_gl_enum target,
			t_gl_sizei *offset_size, const t_gl_void *data);
void	gl_delete_buffers(
			t_gl_context *c, t_gl_sizei n, const t_gl_uint *buffers);
void	gl_create_buffers(t_gl_context *c, t_gl_sizei n, t_gl_uint *buffers);
void	*gl_map_buffer(t_gl_context *c, t_gl_enum target, t_gl_enum access);
void	*gl_map_named_buffer(t_gl_context *c,
			t_gl_uint buffer, t_gl_enum access);
void	gl_named_buffer_data(
			t_gl_context *c, t_gl_uint buffer,
			t_gl_sizei size, const t_gl_void *data);
void	gl_named_buffer_sub_data(
			t_gl_context *c, t_gl_uint buffer,
			t_gl_sizei *offset_size, const t_gl_void *data);

#endif