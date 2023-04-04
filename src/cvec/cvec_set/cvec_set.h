/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_set.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:48:48 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:54:17 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVEC_SET_H
# define CVEC_SET_H

# include <lite_gl.h>

int		cvec_set_cap_float(t_cvector_float *vec, size_t size);
void	cvec_set_val_sz_float(t_cvector_float *vec, float val);
void	cvec_set_val_cap_float(t_cvector_float *vec, float val);

int		cvec_set_cap_gl_buffer(t_cvector_gl_buffer *vec, size_t size);
void	cvec_set_val_sz_gl_buffer(t_cvector_gl_buffer *vec, t_gl_buffer val);
void	cvec_set_val_cap_gl_buffer(t_cvector_gl_buffer *vec, t_gl_buffer val);

int		cvec_set_cap_gl_program(t_cvector_gl_program *vec, size_t size);
void	cvec_set_val_sz_gl_program(t_cvector_gl_program *vec, t_gl_program val);
void	cvec_set_val_cap_gl_program(
			t_cvector_gl_program *vec, t_gl_program val);

int		cvec_set_cap_gl_texture(t_cvector_gl_texture *vec, size_t size);
void	cvec_set_val_sz_gl_texture(t_cvector_gl_texture *vec, t_gl_texture val);
void	cvec_set_val_cap_gl_texture(
			t_cvector_gl_texture *vec, t_gl_texture val);

int		cvec_set_cap_gl_vertex_array(
			t_cvector_gl_vertex_array *vec, size_t size);
void	cvec_set_val_sz_gl_vertex_array(
			t_cvector_gl_vertex_array *vec, t_gl_vertex_array val);
void	cvec_set_val_cap_gl_vertex_array(
			t_cvector_gl_vertex_array *vec, t_gl_vertex_array val);

int		cvec_set_cap_gl_vertex(t_cvector_gl_vertex *vec, size_t size);
void	cvec_set_val_sz_gl_vertex(t_cvector_gl_vertex *vec, t_gl_vertex val);
void	cvec_set_val_cap_gl_vertex(t_cvector_gl_vertex *vec, t_gl_vertex val);

int		cvec_set_cap_vec3(t_cvector_vec3 *vec, size_t size);
void	cvec_set_val_sz_vec3(t_cvector_vec3 *vec, t_vec3 val);
void	cvec_set_val_cap_vec3(t_cvector_vec3 *vec, t_vec3 val);

int		cvec_set_cap_ivec3(t_cvector_ivec3 *vec, size_t size);
void	cvec_set_val_sz_ivec3(t_cvector_ivec3 *vec, t_ivec3 val);
void	cvec_set_val_cap_ivec3(t_cvector_ivec3 *vec, t_ivec3 val);

int		cvec_set_cap_vec2(t_cvector_vec2 *vec, size_t size);
void	cvec_set_val_sz_vec2(t_cvector_vec2 *vec, t_vec2 val);
void	cvec_set_val_cap_vec2(t_cvector_vec2 *vec, t_vec2 val);

#endif