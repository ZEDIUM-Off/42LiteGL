/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_copy.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:40:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:48:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVEC_COPY_H
# define CVEC_COPY_H

# include <lite_gl.h>

int	cvec_copy_float(t_cvector_float *dest, t_cvector_float *src);
int	cvec_copyc_float(void *dest, void *src);

int	cvec_copy_gl_buffer(t_cvector_gl_buffer	*dest, t_cvector_gl_buffer *src);
int	cvec_copyc_gl_buffer(void *dest, void *src);

int	cvec_copy_gl_program(t_cvector_gl_program *dest, t_cvector_gl_program *src);
int	cvec_copyc_gl_program(void *dest, void *src);

int	cvec_copy_gl_texture(t_cvector_gl_texture *dest, t_cvector_gl_texture *src);
int	cvec_copyc_gl_texture(void *dest, void *src);

int	cvec_copy_gl_vertex_array(
		t_cvector_gl_vertex_array *dest, t_cvector_gl_vertex_array *src);
int	cvec_copyc_gl_vertex_array(void *dest, void *src);

int	cvec_copy_gl_vertex(t_cvector_gl_vertex *dest, t_cvector_gl_vertex *src);
int	cvec_copyc_gl_vertex(void *dest, void *src);

int	cvec_copy_vec2(t_cvector_vec2 *dest, t_cvector_vec2 *src);
int	cvec_copyc_vec2(void *dest, void *src);

int	cvec_copy_vec3(t_cvector_vec3 *dest, t_cvector_vec3 *src);
int	cvec_copyc_vec3(void *dest, void *src);

int	cvec_copy_ivec3(t_cvector_ivec3 *dest, t_cvector_ivec3 *src);
int	cvec_copyc_ivec3(void *dest, void *src);

#endif