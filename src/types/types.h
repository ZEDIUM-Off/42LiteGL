/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:13:57 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 14:33:29 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef void (*		t_vert_func) (float *vs_output, void *vertex_attribs,
	Shader_Builtins *builtins, void *uniforms);
typedef void (*		t_frag_func)(float *fs_input,
	Shader_Builtins *builtins, void* uniforms);

typedef void (*		t_draw_triangle_func)(t_GLContext *c,
	t_glVertex **v, unsigned int provoke);

typedef uint8_t		t_u8;
typedef uint16_t	t_u16;
typedef uint32_t	t_u32;
typedef uint64_t	t_u64;
typedef int8_t		t_i8;
typedef int16_t		t_i16;
typedef int32_t		t_i32;
typedef int64_t		t_i64;
typedef uint8_t		t_gl_boolean;
typedef char		t_gl_char;
typedef int8_t		t_gl_byte;
typedef uint8_t		t_gl_ubyte;
typedef int16_t		t_gl_short;
typedef uint16_t	t_gl_ushort;
typedef int32_t		t_gl_int;
typedef uint32_t	t_gl_uint;
typedef int64_t		t_gl_int64;
typedef uint64_t	t_gl_uint64;
typedef int32_t		t_gl_sizei;
typedef int32_t		t_gl_enum;
typedef int32_t		t_gl_bitfield;
typedef intptr_t	t_gl_intptr;
typedef uintptr_t	t_gl_sizeiptr;
typedef void		t_gl_void;
typedef float		t_gl_float;
typedef float		t_gl_clampf;
typedef double		t_gl_double;
typedef double		t_gl_clampd;

#endif