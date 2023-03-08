/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_vertex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:06:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 12:07:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_VERTEX_H
# define GL_VERTEX_H

# include <lite_gl.h>

void	gl_enable_vertex_attrib_array(t_GLContext *c, t_gl_uint index);
void	gl_disable_vertex_attrib_array(t_GLContext *c, t_gl_uint index);
void	gl_vertex_attrib_pointer(t_GLContext *c, GLuint index,
			t_glVertex_Attrib attr, const GLvoid *pointer);

#endif