/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:46:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:31:31 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_DRAW_H
# define GL_DRAW_H

# include <lite_gd.h>

void	pixel_put(t_mlx_env	*env, int x, int y, int color);

void	draw_pixel(t_GLConext *c, t_vec4 cf, t_vec2 pos, float z);

void	run_pipeline(t_GLContext *c, t_pipeline_settings *settings);
void	gl_draw_arrays(t_GLContext *c,
			t_gl_enum mode, t_gl_int first, t_gl_sizei count);

void	point_mode(t_GLContext *c, t_gl_uint first, t_gl_sizei count);
void	line_mode(t_GLContext *c, t_gl_int first, t_gl_sizei count);
void	triangle_mode(t_GLContext *c, t_gl_int first, t_gl_sizei count);
void	line_strip_mode(t_GLContext *c, t_gl_int first, t_gl_sizei count);
void	line_loop_mode(t_GLContext *c, t_gl_int first, t_gl_sizei count);
void	triangle_strip_mode(t_GLContext *c, t_gl_sizei count);
void	triangle_fan_mode(t_GLContext *c, t_gl_sizei count);

void	draw_triangle(t_GLContext *c, t_glVertex **v, unsigned int provoke);
void	draw_triangle_final(t_GLContext *c,
			t_glVertex **v, unsigned int provoke);
void	draw_triangle_fill(t_GLContext *c,
			t_glVertex **v, unsigned int provoke);
void	draw_triangle_clip(
			t_GLContext *c, t_glVertex **v, unsigned int provoke, int clip_bit);

void	set_draw_tri_vars(t_GLContext *c,
			t_draw_tri_vars *vars, t_glVertex **v);

void	draw_point(t_GLContext *c, t_glVertex *vert);
void	draw_line_clip(t_GLContext *c, t_glVertex *v1, t_glVextex *v2);
void	draw_line_shader(t_GLContext *c,
			t_vec4 *vertexes, float **v_out, unsigned int provoke);
void	draw_thick_line_shader(t_GLContext *c,
			t_vec4 *vertexes, float **v_out, unsigned int provoke);
int		draw_perp_line(t_GLContext *c, float slope, float *vx, float *vy);
void	set_perp_line_vars(t_GLContext *c,
			t_draw_line_shader_vars *vars, float *vx, float *vy);
void	set_line_shader_vars(t_GLContext *c, t_draw_line_shader_vars *vars,
			t_vec4 *vertexes, float ***v_out);

#endif
