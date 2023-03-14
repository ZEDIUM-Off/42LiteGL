/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:13:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 19:24:47 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_STRUCT_H
# define GL_STRUCT_H

# include <lite_gl.h>
# include "gl_enum.h"
# include "../cvec/cvec.h"
# include "../gl_math/gl_math.h"

struct s_mlx_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			bpp;
	int			line_len;
	int			endian;
};

struct s_multi_draw_arrays_settings
{
	const t_gl_sizei	*first;
	const t_gl_sizei	*count;
	t_gl_sizei			drawcount;
};

struct s_draw_arrays_instanced_settings
{
	t_gl_int	first;
	t_gl_sizei	count;
	t_gl_sizei	instancecount;
	t_gl_uint	baseinstance;
};

struct s_draw_elements_settings
{
	t_gl_sizei	count;
	t_gl_enum	type;
	t_gl_sizei	offset;
};

struct s_multi_draw_elements_settings
{
	const t_gl_sizei	*count;
	t_gl_enum			type;
	t_gl_sizei			*indices;
	t_gl_sizei			drawcount;
};

struct s_draw_elements_instanced_settings
{
	t_gl_int	first;
	t_gl_sizei	count;
	t_gl_enum	type;
	t_gl_sizei	instancecount;
	t_gl_uint	baseinstance;
	t_gl_sizei	offset;
};

struct s_tex_image_params
{
	t_gl_int	level;
	t_gl_int	xoffset;
	t_gl_int	yoffset;
	t_gl_int	zoffset;
	t_gl_sizei	width;
	t_gl_sizei	height;
	t_gl_sizei	depth;
	t_gl_enum	format;
	t_gl_int	border;
	t_gl_enum	type;
};

struct s_glTexture
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
};

struct s_pipeline_settings
{
	t_gl_enum		mode;
	t_gl_uint		first;
	t_gl_sizei		count;
	t_gl_sizei		instance;
	t_gl_uint		base_instance;
	t_gl_boolean	use_elements;
};

struct s_glVertex
{
	t_vec4		clip_space;
	t_vec4		screen_space;
	int			clip_code;
	int			edge_flag;
	float		*vs_out;
};

struct s_glFramebuffer // surement remplacer par qq chose lie a la mlx
{
	t_u8		*buf;
	t_u8		*lastrow;
	size_t		w;
	size_t		h;
};

struct s_Vertex_Shader_output
{
	int				size;
	t_gl_enum		*interpolation;
	t_cvector_float	output_buf;
};

struct s_glVertex_Attrib
{
	t_gl_int			size;
	t_gl_enum			type;
	t_gl_sizei			stride;
	t_gl_sizeiptr		offset;
	t_gl_boolean		normalized;
	unsigned int		buf;
	t_gl_boolean		enabled;
	t_gl_uint			divisor;
};

struct s_glVertex_Array
{
	t_gl_vertex_attrib	vertex_attribs[GL_MAX_VERTEX_ATTRIBS];
	t_gl_uint			element_buffer;
	t_gl_boolean		deleted;

};

struct s_glBuffer
{
	t_gl_sizei		size;
	t_gl_enum		type;
	t_u8			*data;
	t_gl_boolean	deleted;
	t_gl_boolean	user_owned;
};

struct s_Color // rendre compatible avec mlx
{
	t_u8	r;
	t_u8	g;
	t_u8	b;
	t_u8	a;
};

struct s_Line
{
	float	a;
	float	b;
	float	c;
};

struct s_Plane
{
	t_vec3	n;
	float	d;
};

struct s_Shader_Builtins
{
	t_vec4			gl_position;
	t_gl_int		gl_instance_id;
	t_vec2			gl_point_coord;
	t_gl_boolean	gl_front_facing;
	t_vec4			gl_frag_coord;
	t_vec4			gl_frag_color;
	float			gl_frag_depth;
	t_gl_boolean	discard;
};

struct s_vertex_stage_vars
{
	unsigned int		i;
	int					n;
	unsigned int		vert;
	unsigned int		num_enabled;
	t_u8				*buf_pos;
	float				*vec4_init;
	int					enabled[GL_MAX_VERTEX_ATTRIBS];
	t_gl_vertex_attrib	*v;
	t_gl_uint			elem_buffer;
	t_gl_uint			*uint_array;
	t_gl_ushort			*ushort_array;
	t_gl_ubyte			*ubyte_array;
};

typedef void (*		t_vert_func) (float *vs_output, void *vertex_attribs,
	t_shader_builtins *builtins, void *uniforms);
typedef void (*		t_frag_func) (float *fs_input,
	t_shader_builtins *builtins, void *uniforms);
typedef void (*		t_draw_triangle_func)(t_gl_context *c,
	t_gl_vertex **v, unsigned int provoke);
typedef float (*	t_clip_proc[6])(t_vec4 *, t_vec4 *, t_vec4 *);

struct s_glProgram
{
	t_vert_func		vertex_shader;
	t_frag_func		fragment_shader;
	void			*uniform;
	int				vs_output_size;
	t_gl_enum		interpolation[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	t_gl_boolean	fragdepth_or_discard;
	t_gl_boolean	deleted;
};

struct s_context_settings
{
	t_u32	**back;
	int		w;
	int		h;
	int		bitdepth;
	t_u32	r_mask;
	t_u32	g_mask;
	t_u32	b_mask;
	t_u32	a_mask;
};

struct s_draw_line_shader_vars
{
	float	*x;
	float	*y;
	float	*z;
	float	*w;
	float	slope;
	t_line	line;
	float	t;
	float	lx;
	float	ly;
	float	lz;
	float	lw;
	float	lh;
	t_vec2	p[2];
	t_vec2	pr;
	t_vec2	sub_p;
	t_vec2	ab;
	float	i_x[2];
	float	i_y[2];
	float	x_mima[2];
	float	y_mima[2];
	float	line_len_sq;
	int		diag;
	int		first_is_diag;
};

struct s_draw_tri_vars
{
	t_shader_builtins	builtins;
	t_vec3				h[3];
	float				dzxy[6];
	float				max_depth_slope;
	float				poly_offset;
	float				x_mima[2];
	float				y_mima[2];
	int					i_xy_max[2];
	t_line				lines[3];
	float				alpha;
	float				beta;
	float				gamma;
	float				fs_input[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	float				perspective[GL_MAX_VERTEX_OUTPUT_COMPONENTS * 3];
	float				*vs_output;
	float				x;
	float				y;
	float				z;
	float				tmp;
	float				tmp2;
	float				ix;
	float				iy;
};

struct s_draw_tri_clip_vars
{
	t_gl_vertex	tmp1;
	t_gl_vertex	tmp2;
	t_gl_vertex	**new_v;
	float		tt;
	float		tmp1_out[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	float		tmp2_out[GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	int			edge_flag_tmp;
};

struct s_glContext
{
	t_draw_triangle_func		draw_triangle_front;
	t_draw_triangle_func		draw_triangle_back;
	t_mat4						vp_mat;
	t_clip_proc					clip_proc;
	t_cvector_gl_vertex_array	vertex_arrays;
	t_cvector_gl_buffer			buffers;
	t_cvector_gl_texture		textures;
	t_cvector_gl_program		programs;
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
	t_shader_builtins			builtins;
	t_vertex_shader_output		vs_output;
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
	t_color						clear_color;
	t_vec4						blend_color;
	t_gl_float					point_size;
	t_gl_float					line_width;
	t_gl_float					clear_depth;
	t_gl_float					depth_range_near;
	t_gl_float					depth_range_far;
	t_gl_framebuffer			zbuf;
	t_gl_framebuffer			back_buffer;
	t_gl_framebuffer			stencil_buf;
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
	t_cvector_gl_vertex			glverts;
};

#endif