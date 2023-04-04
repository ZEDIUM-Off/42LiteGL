/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_insert.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:42:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:51:08 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVEC_INSERT_H
# define CVEC_INSERT_H

# include <lite_gl.h>
# include "../cvec.h"

int	cvec_insert_float(t_cvector_float *vec, size_t i, float a);
int	cvec_insert_array_float(t_cvector_float *vec, size_t i, float *a, size_t n);

int	cvec_insert_gl_buffer(t_cvector_gl_buffer *vec, size_t i, t_gl_buffer a);
int	cvec_insert_array_gl_buffer(
		t_cvector_gl_buffer *vec, size_t i, t_gl_buffer *a, size_t n);

int	cvec_insert_gl_program(t_cvector_gl_program *vec, size_t i, t_gl_program a);
int	cvec_insert_array_gl_program(
		t_cvector_gl_program *vec, size_t i, t_gl_program *a, size_t n);

int	cvec_insert_gl_texture(t_cvector_gl_texture *vec, size_t i, t_gl_texture a);
int	cvec_insert_array_gl_texture(
		t_cvector_gl_texture *vec, size_t i, t_gl_texture *a, size_t n);

int	cvec_insert_gl_vertex_array(
		t_cvector_gl_vertex_array *vec, size_t i, t_gl_vertex_array a);
int	cvec_insert_array_gl_vertex_array(
		t_cvector_gl_vertex_array *vec, size_t i,
		t_gl_vertex_array *a, size_t n);

int	cvec_insert_gl_vertex(t_cvector_gl_vertex *vec, size_t i, t_gl_vertex a);
int	cvec_insert_array_gl_vertex(
		t_cvector_gl_vertex *vec, size_t i, t_gl_vertex *a, size_t n);

int	cvec_insert_vec3(t_cvector_vec3 *vec, size_t i, t_vec3 a);
int	cvec_insert_array_vec3(
		t_cvector_vec3 *vec, size_t i, t_vec3 *a, size_t n);

int	cvec_insert_ivec3(t_cvector_ivec3 *vec, size_t i, t_ivec3 a);
int	cvec_insert_array_ivec3(
		t_cvector_ivec3 *vec, size_t i, t_ivec3 *a, size_t n);

int	cvec_insert_vec2(t_cvector_vec2 *vec, size_t i, t_vec2 a);
int	cvec_insert_array_vec2(
		t_cvector_vec2 *vec, size_t i, t_vec2 *a, size_t n);

#endif