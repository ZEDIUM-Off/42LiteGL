/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:13:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 14:56:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_STRUCT_H
# define GL_STRUCT_H

typedef struct glTexture
{
	unsigned int		w;
	unsigned int		h;
	unsigned int		d;
	int					base_level;
	t_gl_enum			mag_filter;
	t_gl_enum			min_filter;
	t_gl_enum			wrap_s;
	t_gl_enum			wrap_t;
	t_gl_enum			wrap_r;
	t_gl_enum			format;
	t_gl_enum			type;
	t_gl_boolean		deleted;
	t_gl_boolean		user_owned;
	t_u8				*data;
}	t_glTexture;

typedef struct pipeline_settings
{
	t_gl_enum		mode;
	t_gl_uint		first;
	t_gl_sizei		count;
	t_gl_sizei		instance;
	t_gl_uint		base_instance;
	t_gl_boolean	use_elements;
}	t_pipeline_settings;

typedef struct glVertex
{
	t_vec4		clip_space;
	t_vec4		screen_space;
	int			clip_code;
	int			edge_flag;
	float		*vs_out;
}	t_glVertex;

typedef struct glFramebuffer // surement remplacer par qq chose lie a la mlx
{
	t_u8		*buf;
	t_u8		*lastrow;
	size_t		w;
	size_t		h;
}	t_glFramebuffer;

typedef struct Vertex_Shader_output
{
	int				size;
	t_gl_enum		*interpolation;
	cvector_float	output_buf;
}	t_Vertex_Shader_output;

typedef struct glVertex_Attrib
{
	t_gl_int			size;
	t_gl_enum			type;
	t_gl_sizei			stride;
	t_gl_sizeiptr		offset;
	t_gl_boolean		normalized;
	unsigned int		buf;
	t_gl_boolean		enabled;
	t_gl_uint			divisor;
}	t_glVertex_Attrib;

typedef struct glVertex_Array
{
	glVertex_Attrib	vertex_attribs[GL_MAX_VERTEX_ATTRIBS];
	t_gl_uint		element_buffer;
	t_gl_boolean	deleted;

}	t_glVertex_Array;

typedef struct glBuffer
{
	t_gl_sizei		size;
	t_gl_enum		type;
	t_u8			*data;
	t_gl_boolean	deleted;
	t_gl_boolean	user_owned;
}	t_glBuffer;

typedef struct cvector_glBuffer
{
	t_glBuffer	*a;
	size_t		size;
	size_t		capacity;
}	t_cvector_glBuffer;

typedef struct Color // rendre compatible avec mlx
{
	t_u8	r;
	t_u8	g;
	t_u8	b;
	t_u8	a;
}	t_color;

typedef struct Line
{
	float	a;
	float	b;
	float	c;
}	t_line;

typedef struct Plane
{
	t_vec3	n;
	float	d;
}	t_plane;

typedef struct cvector_float
{
	float		*a;
	size_t		size;
	size_t		capacity;
}	t_cvector_float;

typedef struct Shader_Builtins
{
	t_vec4			gl_position;
	t_t_gl_int		gl_instance_id;
	t_vec2			gl_point_coord;
	t_gl_boolean	gl_front_facing;
	t_vec4			gl_frag_coord;
	t_vec4			gl_frag_color;
	float			gl_frag_depth;
	t_gl_boolean	discard;
}	t_Shader_Builtins;

typedef struct glProgram
{
	vert_func		vertex_shader;
	frag_func		fragment_shader;
	void			*uniform;
	int				vs_output_size;
	t_gl_enum		interpolation[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	t_gl_boolean	fragdepth_or_discard;
	t_gl_boolean	deleted;
}	t_glProgram;

typedef struct glContext
{
	t_mat4						vp_mat;
	t_cvector_glVertex_Array	vertex_arrays;
	t_cvector_glBuffer			buffers;
	t_cvector_glTexture			textures;
	t_cvector_glProgram			programs;
	int							x_min;
	int							y_min;
	size_t						x_max;
	size_t						y_max;
	t_gl_uint					bound_buffers[GL_NUM_BUFFER_TYPES
		- GL_ARRAY_BUFFER];
	t_gl_uint					bound_textures[GL_NUM_TEXTURE_TYPES
		- GL_TEXTURE_UNBOUND - 1];
	t_gl_uint					cur_texture2d;
	t_gl_uint					cur_program;
	t_gl_uint					cur_vertex_array;
	t_gl_enum					error;
	void						*uniform;
	t_vec4						vertex_attribs_vs[GL_MAX_VERTEX_ATTRIBS];
	Shader_Builtins				builtins;
	Vertex_Shader_output		vs_output;
	float						fs_input[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	t_gl_boolean				depth_test;
	t_gl_boolean				line_smooth;
	t_gl_boolean				cull_face;
	t_gl_boolean				fragdepth_or_discard;
	t_gl_boolean				depth_clamp;
	t_gl_boolean				depth_mask;
	t_gl_boolean				blend;
	t_gl_boolean				logic_ops;
	t_gl_boolean				poly_offset;
	t_gl_boolean				scissor_test;
	t_gl_boolean				stencil_test;
	t_gl_uint					stencil_writemask;
	t_gl_uint					stencil_writemask_back;
	t_gl_int					stencil_ref;
	t_gl_int					stencil_ref_back;
	t_gl_uint					stencil_valuemask;
	t_gl_uint					stencil_valuemask_back;
	t_gl_enum					stencil_func;
	t_gl_enum					stencil_func_back;
	t_gl_enum					stencil_sfail;
	t_gl_enum					stencil_dpfail;
	t_gl_enum					stencil_dppass;
	t_gl_enum					stencil_sfail_back;
	t_gl_enum					stencil_dpfail_back;
	t_gl_enum					stencil_dppass_back;
	t_gl_enum					logic_func;
	t_gl_enum					blend_sfactor;
	t_gl_enum					blend_dfactor;
	t_gl_enum					blend_equation;
	t_gl_enum					cull_mode;
	t_gl_enum					front_face;
	t_gl_enum					poly_mode_front;
	t_gl_enum					poly_mode_back;
	t_gl_enum					depth_func;
	t_gl_enum					point_spr_origin;
	t_gl_enum					provoking_vert;
	t_gl_float					poly_factor;
	t_gl_float					poly_units;
	t_gl_int					scissor_lx;
	t_gl_int					scissor_ly;
	t_gl_sizei					scissor_ux;
	t_gl_sizei					scissor_uy;
	t_gl_int					unpack_alignment;
	t_gl_int					pack_alignment;
	t_gl_int					clear_stencil;
	t_Color						clear_color;
	t_vec4						blend_color;
	t_gl_float					point_size;
	t_gl_float					line_width;
	t_gl_float					clear_depth;
	t_gl_float					depth_range_near;
	t_gl_float					depth_range_far;
	glFramebuffer				zbuf;
	glFramebuffer				back_buffer;
	glFramebuffer				stencil_buf;
	int							user_alloced_backbuf;
	int							bitdepth;
	t_u32						r_mask;
	t_u32						g_mask;
	t_u32						b_mask;
	t_u32						a_mask;
	int							r_shift;
	int							g_shift;
	int							b_shift;
	int							a_shift;
	cvector_glVertex			glverts;
}	t_GLcontext;

#endif