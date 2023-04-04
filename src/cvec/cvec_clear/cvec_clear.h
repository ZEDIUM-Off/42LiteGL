/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_clear.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:36:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/03 12:47:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVEC_CLEAR_H
# define CVEC_CLEAR_H

# include <lite_gl.h>

void	cvec_clear_float(t_cvector_float *vec);
void	cvec_free_float_heap(void *vec);
void	cvec_free_float(void *vec);

void	cvec_clear_gl_buffer(t_cvector_gl_buffer *vec);
void	cvec_free_gl_buffer_heap(void *vec);
void	cvec_free_gl_buffer(void *vec);

void	cvec_clear_gl_program(t_cvector_gl_program *vec);
void	cvec_free_gl_program_heap(void *vec);
void	cvec_free_gl_program(void *vec);

void	cvec_clear_gl_texture(t_cvector_gl_texture *vec);
void	cvec_free_gl_texture_heap(void *vec);
void	cvec_free_gl_texture(void *vec);

void	cvec_clear_gl_vertex_array(t_cvector_gl_vertex_array *vec);
void	cvec_free_gl_vertex_array_heap(void *vec);
void	cvec_free_gl_vertex_array(void *vec);

void	cvec_clear_gl_vertex(t_cvector_gl_vertex *vec);
void	cvec_free_gl_vertex_heap(void *vec);
void	cvec_free_gl_vertex(void *vec);

void	cvec_clear_vec3(t_cvector_vec3 *vec);
void	cvec_free_vec3_heap(void *vec);
void	cvec_free_vec3(void *vec);

void	cvec_clear_ivec3(t_cvector_ivec3 *vec);
void	cvec_free_ivec3_heap(void *vec);
void	cvec_free_iec3(void *vec);

void	cvec_clear_vec2(t_cvector_vec2 *vec);
void	cvec_free_vec2_heap(void *vec);
void	cvec_free_vec2(void *vec);

#endif