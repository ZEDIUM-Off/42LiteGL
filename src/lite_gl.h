/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lite_gl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:31:11 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 12:47:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITE_GL_H
# define LITE_GL_H

# define GL_FALSE 0
# define GL_TRUE 1

# define MAX_VERTICES 500000
# define GL_MAX_VERTEX_ATTRIBS 16
# define GL_MAX_VERTEX_OUTPUT_COMPONENTS 64
# define GL_MAX_DRAW_BUFFERS 8
# define GL_MAX_COLOR_ATTACHMENTS 8

# define EPSILON 0.000001

# include "types/types.h"
# include "types/gl_enum.h"
# include "types/gl_struct.h"

# include "gl_math/gl_math.h"
# include "gl_color/color.h"
# include "gl_line/gl_line.h"
# include "glBuffers/gl_buffer.h"
# include "gl_vertex/gl_vertex.h"
# include "gl_shader/gl_shader.h"
# include "gl_draw/gl_draw.h"
# include "gl_line/gl_line.h"

#endif