/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:23:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:56:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVEC_H
# define CVEC_H

# include <lite_gl.h>
# include "cvec_clear/cvec_clear.h"
# include "cvec_copy/cvec_copy.h"
# include "cvec_insert/cvec_insert.h"
# include "cvec_push_pop/cvec_push_pop.h"
# include "cvec_set/cvec_set.h"
# include "cvec_utils/cvec_utils.h"

struct s_cvector_float
{
	float	*a;
	size_t	size;
	size_t	capacity;
};

struct s_cvector_glVertex_Array
{
	t_gl_vertex_array	*a;
	size_t				size;
	size_t				capacity;
};

struct s_cvector_gl_buffer
{
	t_gl_buffer	*a;
	size_t		size;
	size_t		capacity;
};

struct s_cvector_gl_vertex
{
	t_gl_vertex	*a;
	size_t		size;
	size_t		capacity;
};

struct s_cvector_gl_texture
{
	t_gl_texture	*a;
	size_t			size;
	size_t			capacity;
};

struct s_cvector_gl_program
{
	t_gl_program	*a;
	size_t			size;
	size_t			capacity;
};

struct s_cvector_vec3
{
	t_vec3	*a;
	size_t	size;
	size_t	capacity;
};

struct s_cvector_ivec3
{
	t_ivec3	*a;
	size_t	size;
	size_t	capacity;
};

struct s_cvector_vec2
{
	t_vec2	*a;
	size_t	size;
	size_t	capacity;
};

int							cvec_float(
								t_cvector_float *vec,
								size_t size, size_t capacity);
int							cvec_init_float(
								t_cvector_float *vec, float *vals, size_t num);
t_cvector_float				*cvec_float_heap(size_t size, size_t capacity);
t_cvector_float				*cvec_init_float_heap(float *vals, size_t num);
int							cvec_extend_float(t_cvector_float *vec, size_t num);

int							cvec_gl_buffer(
								t_cvector_gl_buffer *vec,
								size_t size, size_t capacity);
int							cvec_init_gl_buffer(
								t_cvector_gl_buffer *vec,
								t_gl_buffer *vals, size_t num);
t_cvector_gl_buffer			*cvec_gl_buffer_heap(size_t size, size_t capacity);
t_cvector_gl_buffer			*cvec_init_gl_buffer_heap(
								t_gl_buffer *vals, size_t num);
int							cvec_extend_gl_buffer(t_cvector_gl_buffer *vec,
								size_t num);

int							cvec_gl_program(
								t_cvector_gl_program *vec,
								size_t size, size_t capacity);
int							cvec_init_gl_program(
								t_cvector_gl_program *vec,
								t_gl_program *vals, size_t num);
t_cvector_gl_program		*cvec_gl_program_heap(size_t size, size_t capacity);
t_cvector_gl_program		*cvec_init_gl_program_heap(
								t_gl_program *vals, size_t num);
int							cvec_extend_gl_program(t_cvector_gl_program *vec,
								size_t num);

int							cvec_gl_texture(
								t_cvector_gl_texture *vec,
								size_t size, size_t capacity);
int							cvec_init_gl_texture(
								t_cvector_gl_texture *vec,
								t_gl_texture *vals, size_t num);
t_cvector_gl_texture		*cvec_gl_texture_heap(size_t size, size_t capacity);
t_cvector_gl_texture		*cvec_init_gl_texture_heap(
								t_gl_texture *vals, size_t num);
int							cvec_extend_gl_texture(t_cvector_gl_texture *vec,
								size_t num);

int							cvec_gl_vertex_array(
								t_cvector_gl_vertex_array *vec,
								size_t size, size_t capacity);
int							cvec_init_gl_vertex_array(
								t_cvector_gl_vertex_array *vec,
								t_gl_vertex_array *vals, size_t num);
t_cvector_gl_vertex_array	*cvec_gl_vertex_array_heap(
								size_t size, size_t capacity);
t_cvector_gl_vertex_array	*cvec_init_gl_vertex_array_heap(
								t_gl_vertex_array *vals, size_t num);
int							cvec_extend_gl_vertex_array(
								t_cvector_gl_vertex_array *vec, size_t num);

int							cvec_gl_vertex(
								t_cvector_gl_vertex *vec,
								size_t size, size_t capacity);
int							cvec_init_gl_vertex(
								t_cvector_gl_vertex *vec,
								t_gl_vertex *vals, size_t num);
t_cvector_gl_vertex			*cvec_gl_vertex_heap(
								size_t size, size_t capacity);
t_cvector_gl_vertex			*cvec_init_gl_vertex_heap(
								t_gl_vertex *vals, size_t num);
int							cvec_extend_gl_vertex(
								t_cvector_gl_vertex *vec, size_t num);

int							cvec_vec3(
								t_cvector_vec3 *vec,
								size_t size, size_t capacity);
int							cvec_init_vec3(
								t_cvector_vec3 *vec,
								t_vec3 *vals, size_t num);
t_cvector_vec3				*cvec_vec3_heap(
								size_t size, size_t capacity);
t_cvector_vec3				*cvec_init_vec3_heap(
								t_vec3 *vals, size_t num);
int							cvec_extend_vec3(
								t_cvector_vec3 *vec, size_t num);

int							cvec_vec2(
								t_cvector_vec2 *vec,
								size_t size, size_t capacity);
int							cvec_init_vec2(
								t_cvector_vec2 *vec,
								t_vec2 *vals, size_t num);
t_cvector_vec2				*cvec_vec2_heap(
								size_t size, size_t capacity);
t_cvector_vec2				*cvec_init_vec2_heap(
								t_vec2 *vals, size_t num);
int							cvec_extend_vec2(
								t_cvector_vec2 *vec, size_t num);

int							cvec_ivec3(
								t_cvector_ivec3 *vec,
								size_t size, size_t capacity);
int							cvec_init_ivec3(
								t_cvector_ivec3 *vec,
								t_ivec3 *vals, size_t num);
t_cvector_ivec3				*cvec_ivec3_heap(
								size_t size, size_t capacity);
t_cvector_ivec3				*cvec_init_ivec3_heap(
								t_ivec3 *vals, size_t num);
int							cvec_extend_ivec3(
								t_cvector_ivec3 *vec, size_t num);

#endif