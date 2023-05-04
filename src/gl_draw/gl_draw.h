/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:46:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/03 16:38:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_DRAW_H
# define GL_DRAW_H

# include <lite_gl.h>

void	draw_pixel(t_gl_context *c, t_vec4 cf, t_vec2 pos, float z);

void	run_pipeline(t_gl_context *c, t_pipeline_settings *settings);
void	gl_draw_arrays(t_gl_context *c,
			t_gl_enum mode, t_gl_int first, t_gl_sizei count);
void	gl_multi_draw_arrays(
			t_gl_context *c, t_gl_enum mode,
			t_multi_draw_arrays_settings *sett);
void	gl_draw_arrays_instanced(
			t_gl_context *c, t_gl_enum mode,
			t_draw_arrays_instanced_settings *sett);
void	gl_draw_arrays_instanced_base_instance(
			t_gl_context *c, t_gl_enum mode,
			t_draw_arrays_instanced_settings*sett);
void	gl_draw_elements(
			t_gl_context *c, t_gl_enum mode, t_draw_elements_settings *sett);
void	gl_multi_draw_elements(
			t_gl_context *c, t_gl_enum mode,
			t_multi_draw_elements_settings *sett);
void	gl_draw_elements_instanced(
			t_gl_context *c, t_gl_enum mode,
			t_draw_elements_instanced_settings *sett);
void	gl_draw_elements_instanced_base_instance(
			t_gl_context *c, t_gl_enum mode,
			t_draw_elements_instanced_settings *sett);

void	point_mode(t_gl_context *c, t_gl_uint first, t_gl_sizei count);
void	line_mode(t_gl_context *c, t_gl_int first, t_gl_sizei count);
void	triangle_mode(t_gl_context *c, t_gl_int first, t_gl_sizei count);
void	line_strip_mode(t_gl_context *c, t_gl_int first, t_gl_sizei count);
void	line_loop_mode(t_gl_context *c, t_gl_int first, t_gl_sizei count);
void	triangle_strip_mode(t_gl_context *c, t_gl_sizei count);
void	triangle_fan_mode(t_gl_context *c, t_gl_sizei count);

void	draw_triangle(t_gl_context *c, t_gl_vertex **v, unsigned int provoke);
void	draw_triangle_final(t_gl_context *c,
			t_gl_vertex **v, unsigned int provoke);
void	draw_triangle_fill(t_gl_context *c,
			t_gl_vertex **v, unsigned int provoke);
void	draw_triangle_clip(
			t_gl_context *c, t_gl_vertex **v,
			unsigned int provoke, int clip_bit);
void	draw_triangle_point(
			t_gl_context *c, t_gl_vertex **vert, unsigned int provoke);
void	draw_triangle_line(
			t_gl_context *c, t_gl_vertex **v, unsigned int provoke);

void	set_draw_tri_vars(t_gl_context *c,
			t_draw_tri_vars *vars, t_gl_vertex **v);
void	set_draw_tri_clip_vars(t_draw_tri_clip_vars *vars);

void	draw_point(t_gl_context *c, t_gl_vertex *vert);
void	draw_line_clip(t_gl_context *c, t_gl_vertex *v1, t_gl_vertex *v2);
void	draw_line_shader(t_gl_context *c,
			t_vec4 *vertexes, float v_out[2][2], unsigned int provoke);
void	draw_thick_line_shader(t_gl_context *c,
			t_vec4 *vertexes, float v_out[2][2], unsigned int provoke);
int		draw_perp_line(t_gl_context *c, float slope, float *vx, float *vy);
void	set_perp_line_vars(t_gl_context *c,
			t_draw_line_shader_vars *vars, float *vx, float *vy);
void	set_line_shader_vars(t_gl_context *c, t_draw_line_shader_vars *vars,
			t_vec4 *vertexes, float v_out[2][2]);

#endif
