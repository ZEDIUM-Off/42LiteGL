/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_push_pop.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:43:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:46:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVEC_PUSH_POP_H
# define CVEC_PUSH_POP_H

# include <lite_gl.h>

int					cvec_push_float(t_cvector_float *vec, float a);
float				cvec_pop_float(t_cvector_float *vec);

int					cvec_push_gl_buffer(
						t_cvector_gl_buffer *vec, t_gl_buffer a);
t_gl_buffer			cvec_pop_gl_buffer(t_cvector_gl_buffer *vec);

int					cvec_push_gl_program(
						t_cvector_gl_program *vec, t_gl_program a);
t_gl_program		cvec_pop_gl_program(t_cvector_gl_program *vec);

int					cvec_push_gl_texture(
						t_cvector_gl_texture *vec, t_gl_texture a);
t_gl_texture		cvec_pop_gl_texture(t_cvector_gl_texture *vec);

int					cvec_push_gl_vertex_array(
						t_cvector_gl_vertex_array *vec, t_gl_vertex_array a);
t_gl_vertex_array	cvec_pop_gl_vertex_array(t_cvector_gl_vertex_array *vec);

int					cvec_push_gl_vertex(
						t_cvector_t_gl_vertex *vec, t_gl_vertex a);
t_gl_vertex			cvec_pop_gl_vertex(t_cvector_t_gl_vertex *vec);

#endif