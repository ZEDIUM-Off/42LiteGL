/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_vertex_arrays.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:42:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 15:27:16 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_VERTEX_ARRAYS_H
# define GL_VERTEX_ARRAYS_H

# include <lite_gl.h>

void	gl_bind_vertex_array(t_gl_context *c, t_gl_uint array);
void	gl_delete_vertex_arrays(t_gl_context *c, t_gl_sizei n,
			t_gl_uint *arrays);
void	gl_gen_vertex_arrays(t_gl_context *c, t_gl_sizei n, t_gl_uint *arrays);
void	init_gl_vertex_array(t_gl_vertex_array *v);

#endif