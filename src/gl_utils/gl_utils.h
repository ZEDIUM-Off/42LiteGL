/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:26:21 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/30 11:18:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_UTILS_H
# define GL_UTILS_H

# include <lite_gl.h>

void			gl_blend_func(
					t_gl_context *c, t_gl_enum sfactor, t_gl_enum dfactor);
void			gl_blend_equation(t_gl_context *c, t_gl_enum mode);
void			gl_blend_color(t_gl_context *c, t_gl_clampf *color);
t_gl_enum		gl_check_framebuffer_status(t_gl_context *c, t_gl_enum target);
void			gl_clear_stencil(t_gl_context *c, t_gl_int s);
void			gl_clear(t_gl_context *c, t_gl_bitfield mask);
void			gl_clear_depth(t_gl_context *c, t_gl_clampd depth);
void			gl_depth_func(t_gl_context *c, t_gl_enum func);
void			gl_depth_mask(t_gl_context *c, t_gl_boolean flag);
void			gl_depth_range(t_gl_context *c, t_gl_clampf near,
					t_gl_clampf far);
void			gl_cull_face(t_gl_context *c, t_gl_enum mode);
void			gl_front_face(t_gl_context *c, t_gl_enum mode);
void			gl_line_width(t_gl_context *c, t_gl_float width);
void			gl_logic_op(t_gl_context *c, t_gl_enum opcode);
void			gl_enable(t_gl_context *c, t_gl_enum cap);
void			gl_disable(t_gl_context *c, t_gl_enum cap);
void			gl_point_size(t_gl_context *c, t_gl_float size);
void			gl_point_parameteri(t_gl_context *c,
					t_gl_enum pname, t_gl_int param);
void			gl_polygon_offset(t_gl_context *c,
					t_gl_float factor, t_gl_float units);
void			poly_point_mode(t_gl_context *c, t_gl_enum face,
					t_gl_enum mode);
void			poly_line_mode(t_gl_context *c, t_gl_enum face, t_gl_enum mode);
void			poly_fill_mode(t_gl_context *c, t_gl_enum face, t_gl_enum mode);
void			gl_polygon_mode(t_gl_context *c, t_gl_enum face,
					t_gl_enum mode);
void			gl_provoking_vertex(t_gl_context *c, t_gl_enum mode);
void			gl_scissor(t_gl_context *c, t_gl_int *xy, t_gl_sizei *wh);
void			gl_stencil_func_separate(t_gl_context *c, t_gl_enum *face_func,
					t_gl_int ref, t_gl_uint mask);
void			gl_stencil_func(t_gl_context *c, t_gl_enum func,
					t_gl_int ref, t_gl_uint mask);
void			gl_stencil_mask(t_gl_context *c, t_gl_uint mask);
void			gl_stencil_mask_separate(t_gl_context *c, t_gl_enum face,
					t_gl_uint mask);
void			gl_stencil_op_separate(t_gl_context *c, t_gl_enum face,
					t_gl_enum *sfail_dpfail, t_gl_enum dppass);
void			gl_stencil_op(t_gl_context*c, t_gl_enum sfail,
					t_gl_enum dpfail, t_gl_enum dppass);
void			lgl_set_uniform(t_gl_context *c, void *uniform);
void			*gl_resize_frame_buffer(t_gl_context *c, size_t w, size_t h);
void			gl_viewport(t_gl_context *c, int *xy, t_gl_sizei *wh);
void			get_shift(t_u32 mask, int *shift);
int				wrap(int i, int size, t_gl_enum mode);
float			map(float value, float new_min, float new_max);
void			setup_fs_input(
					t_gl_context *c, float **vs_out,
					t_draw_line_shader_vars *v, unsigned int provoke);
void			init_clip_proc(t_gl_context *c);
int				gl_clipcode(t_gl_context *c, t_vec4 pt);
void			update_clip_pt(
					t_gl_context *c, t_gl_vertex *q, t_gl_vertex **v, float t);
int				is_front_facing(t_gl_context *c,
					t_gl_vertex *v1, t_gl_vertex *v2, t_gl_vertex *v3);
int				depthtest(t_gl_context *c, float zval, float zbufval);
void			stencil_op(t_gl_context *c, int stencil, int depth, t_u8 *dest);
int				stencil_test(t_gl_context *c, t_u8 stencil);
t_color			blend_pixel(t_gl_context *c, t_vec4 src, t_vec4 dst);
t_color			logic_ops_pixel(t_gl_context *c, t_color s, t_color d);
void			vertex_stage(t_gl_context *c, t_pipeline_settings *sett);
void			do_vertex(
					t_gl_context *c, t_vertex_stage_vars *vars,
					unsigned int i, unsigned int vert);
void			set_err(t_gl_context *c, t_gl_enum err);

float			clip_xmin(t_vec4 *c, t_vec4 *a, t_vec4 *b);
float			clip_xmax(t_vec4 *c, t_vec4 *a, t_vec4 *b);
float			clip_ymin(t_vec4 *c, t_vec4 *a, t_vec4 *b);
float			clip_ymax(t_vec4 *c, t_vec4 *a, t_vec4 *b);
float			clip_zmin(t_vec4 *c, t_vec4 *a, t_vec4 *b);
float			clip_zmax(t_vec4 *c, t_vec4 *a, t_vec4 *b);
#endif
