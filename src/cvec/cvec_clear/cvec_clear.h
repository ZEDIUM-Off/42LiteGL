/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_clear.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:36:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 09:39:25 by  mchenava        ###   ########.fr       */
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

#endif