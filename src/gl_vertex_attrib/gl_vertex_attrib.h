/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_vertex_attrib.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:06:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 15:26:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_VERTEX_ATTRIB_H
# define GL_VERTEX_ATTRIB_H

# include <lite_gl.h>

void	gl_enable_vertex_attrib_array(t_gl_context *c, t_gl_uint index);
void	gl_disable_vertex_attrib_array(t_gl_context *c, t_gl_uint index);
void	gl_vertex_attrib_pointer(t_gl_context *c, t_gl_uint index,
			t_gl_vertex_attrib attr, const t_gl_void *pointer);
void	init_gl_vertex_attrib(t_gl_vertex_attrib *v);

#endif