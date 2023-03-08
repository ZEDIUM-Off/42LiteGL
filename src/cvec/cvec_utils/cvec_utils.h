/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:50:46 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:55:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVEC_UTILS_H
# define CVEC_UTILS_H

# include <lite_gl.h>

float				cvec_replace_float(t_cvector_float *vec, size_t i, float a);
void				cvec_erase_float(
						t_cvector_float *vec, size_t start, size_t end);
int					cvec_reserve_float(t_cvector_float *vec, size_t size);
float				*cvec_back_float(t_cvector_float *vec);

t_gl_buffer			cvec_replace_gl_buffer(
						t_cvector_gl_buffer *vec, size_t i, t_gl_buffer a);
void				cvec_erase_gl_buffer(
						t_cvector_gl_buffer *vec, size_t start, size_t end);
int					cvec_reserve_gl_buffer(
						t_cvector_gl_buffer *vec, size_t size);
t_gl_buffer			*cvec_back_gl_buffer(t_cvector_gl_buffer *vec);

t_gl_program		cvec_replace_gl_program(
						t_cvector_gl_program *vec, size_t i, t_gl_program a);
void				cvec_erase_gl_program(
						t_cvector_gl_program *vec, size_t start, size_t end);
int					cvec_reserve_gl_program(
						t_cvector_gl_program *vec, size_t size);
t_gl_program		*cvec_back_gl_program(t_cvector_gl_program *vec);

t_gl_texture		cvec_replace_gl_texture(
						t_cvector_gl_texture *vec, size_t i, t_gl_texture a);
void				cvec_erase_gl_texture(
						t_cvector_gl_texture *vec, size_t start, size_t end);
int					cvec_reserve_gl_texture(
						t_cvector_gl_texture *vec, size_t size);
t_gl_texture		*cvec_back_gl_texture(t_cvector_gl_texture *vec);

t_gl_vertex_array	cvec_replace_gl_vertex_array(
						t_cvector_gl_vertex_array *vec, size_t i,
						t_gl_vertex_array a);
void				cvec_erase_gl_vertex_array(
						t_cvector_gl_vertex_array *vec,
						size_t start, size_t end);
int					cvec_reserve_gl_vertex_array(
						t_cvector_gl_vertex_array *vec, size_t size);
t_gl_vertex_array	*cvec_back_gl_vertex_array(t_cvector_gl_vertex_array *vec);

t_gl_vertex			cvec_replace_gl_vertex(
						t_cvector_t_gl_vertex *vec, size_t i, t_gl_vertex a);
void				cvec_erase_gl_vertex(
						t_cvector_t_gl_vertex *vec, size_t start, size_t end);
int					cvec_reserve_gl_vertex(
						t_cvector_t_gl_vertex *vec, size_t size);
t_gl_vertex			*cvec_back_gl_vertex(t_cvector_t_gl_vertex *vec);

#endif