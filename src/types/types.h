/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:46:16 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 18:13:19 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_multi_draw_arrays_settings	t_multi_draw_arrays_settings;
typedef struct s_draw_arrays_instanced_settings \
											t_draw_arrays_instanced_settings;
typedef struct s_draw_elements_settings		t_draw_elements_settings;
typedef struct s_multi_draw_elements_settings \
											t_multi_draw_elements_settings;
typedef struct s_draw_elements_instanced_settings \
											t_draw_elements_instanced_settings;

typedef struct s_draw_tri_vars				t_draw_tri_vars;
typedef struct s_draw_tri_clip_vars			t_draw_tri_clip_vars;
typedef struct s_draw_line_shader_vars		t_draw_line_shader_vars;
typedef struct s_tex_image_params			t_tex_image_params;

typedef struct s_mlx_env					t_mlx_env;

typedef struct s_glContext					t_gl_context;
typedef struct s_glTexture					t_gl_texture;
typedef struct s_pipeline_settings			t_pipeline_settings;
typedef struct s_glVertex					t_gl_vertex;
typedef struct s_glFramebuffer				t_gl_framebuffer;
typedef struct s_Vertex_Shader_output		t_vertex_shader_output;
typedef struct s_glVertex_Attrib			t_gl_vertex_attrib;
typedef struct s_glVertex_Array				t_gl_vertex_array;
typedef struct s_glBuffer					t_gl_buffer;
typedef struct s_Color						t_color;
typedef struct s_Line						t_line;
typedef struct s_Plane						t_plane;
typedef struct s_Shader_Builtins			t_shader_builtins;
typedef struct s_glProgram					t_gl_program;
typedef struct s_context_settings			t_context_settings;
typedef struct s_vertex_stage_vars			t_vertex_stage_vars;

typedef struct s_cvector_float				t_cvector_float;
typedef struct s_cvector_glVertex_Array		t_cvector_gl_vertex_array;
typedef struct s_cvector_gl_buffer			t_cvector_gl_buffer;
typedef struct s_cvector_gl_vertex			t_cvector_gl_vertex;
typedef struct s_cvector_gl_texture			t_cvector_gl_texture;
typedef struct s_cvector_gl_program			t_cvector_gl_program;

typedef float								**t_mat2;
typedef float								**t_mat3;
typedef float								**t_mat4;
typedef struct s_vec2						t_vec2;
typedef struct s_vec3						t_vec3;
typedef struct s_vec4						t_vec4;

typedef uint8_t				t_u8;
typedef uint16_t			t_u16;
typedef uint32_t			t_u32;
typedef uint64_t			t_u64;
typedef int8_t				t_i8;
typedef int16_t				t_i16;
typedef int32_t				t_i32;
typedef int64_t				t_i64;
typedef uint8_t				t_gl_boolean;
typedef char				t_gl_char;
typedef int8_t				t_gl_byte;
typedef uint8_t				t_gl_ubyte;
typedef int16_t				t_gl_short;
typedef uint16_t			t_gl_ushort;
typedef int32_t				t_gl_int;
typedef uint32_t			t_gl_uint;
typedef int64_t				t_gl_int64;
typedef uint64_t			t_gl_uint64;
typedef int32_t				t_gl_sizei;
typedef int32_t				t_gl_enum;
typedef int32_t				t_gl_bitfield;
typedef intptr_t			t_gl_intptr;
typedef uintptr_t			t_gl_sizeiptr;
typedef void				t_gl_void;
typedef float				t_gl_float;
typedef float				t_gl_clampf;
typedef double				t_gl_double;
typedef double				t_gl_clampd;

#endif