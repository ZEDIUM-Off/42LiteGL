/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:07:59 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 12:12:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_BUFFER_H
# define GL_BUFFER_H

# include <lite_gl.h>

void	gl_buffer_data(t_GLContext *c,
			t_gl_enum target, t_gl_sizei size, const t_gl_void *data);
void	gl_bind_buffer(t_GLContext *c, t_gl_enum target, t_gl_uint buffer);
void	gl_gen_buffers(t_GLContext *c, t_gl_sizei n, t_gl_uint *buffers);

#endif