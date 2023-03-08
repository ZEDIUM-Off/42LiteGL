/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_context_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:56:18 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/08 13:40:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	set_bufs(t_GLContext *c, t_context_settings *s)
{
	c->x_min = 0;
	c->x_max = s->w;
	c->y_min = 0;
	c->y_max = s->h;
	c->z_buf.w = s->w;
	c->z_buf.h = s->h;
	c->z_buf.lastrow = c->z_buf.buf + (s->h - 1) * s->w * sizeof(float);
	c->stencil_buf.w = s->w;
	c->stencil_buf.h = s->h;
	c->stencil_buf.lastrow = c->stencil_buf.buf + (s->h - 1) * s->w;
	c->back_buffer.w = s->w;
	c->back_buffer.h = s->h;
	c->back_buffer.buf = (u8 *) *(s->back);
	c->back_buffer.lastrow = c->back_buffer.buf
		+ (s->h - 1) * s->w * sizeof(u32);
	c->bitdepth = s->bitdepth;
	c->r_mask = s->r_mask;
	c->g_mask = s->g_mask;
	c->b_mask = s->b_mask;
	c->a_mask = s->a_mask;
	get_shift(s->r_mask, c->r_shift);
	get_shift(s->g_mask, c->g_shift);
	get_shift(s->b_mask, c->b_shift);
	get_shift(s->a_mask, c->a_shift);
}

void	set_text(t_GLContext *c)
{
	t_glTexture			tmp_tex;

	tmp_tex.type = GL_TEXTURE_UNBOUND;
	tmp_tex.mag_filter = GL_LINEAR;
	tmp_tex.min_filter = GL_LINEAR;
	tmp_tex.wrap_s = GL_REPEAT;
	tmp_tex.wrap_t = GL_REPEAT;
	tmp_tex.wrap_r = GL_REPEAT;
	tmp_tex.data = NULL;
	tmp_tex.deleted = GL_FALSE;
	tmp_tex.user_owned = GL_TRUE;
	tmp_tex.format = GL_RGBA;
	tmp_tex.w = 0;
	tmp_tex.h = 0;
	tmp_tex.d = 0;
	cvec_push_gl_texture(&c->textures, tmp_tex);
}

void	set_cvec(t_GLContext *c)
{
	t_glProgram			tmp_prog;
	t_glVertex_Array	tmp_va;
	t_glBuffer			tmp_buf;

	cvec_gl_vertex_array(&c->vertex_arrays, 0, 3);
	cvec_gl_buffer(&c->buffers, 0, 3);
	cvec_gl_program(&c->programs, 0, 3);
	cvec_gl_texture(&c->textures, 0, 1);
	cvec_gl_vertex(&c->glverts, 0, 10);
	cvec_float(&c->vs_output.output_buf, 0, 0);
	tmp_prog = {default_vs, default_fs, NULL, GL_FALSE};
	cvec_push_gl_program(&c->programs, tmp_prog);
	c->cur_program = 0;
	init_gl_vertex_array(&tmp_va);
	cvec_push_gl_vertex_array(&c->vertex_arrays, tmp_va);
	c->cur_vertex_array = 0;
	tmp_buf.user_owned = GL_TRUE;
	tmp_buf.deleted = GL_FALSE;
	cvec_push_gl_buffer(&c->buffers, tmp_buf);
	set_text(c);
}

void	set_context_vars(t_GLContext *c, t_context_settings *s)
{
	set_bufs(c, s);
	set_cvec(c);
	c->clear_stencil = 0;
	c->clear_color = make_color(0, 0, 0, 0);
	set_vec4(c->blend_color, 0, 0, 0, 0);
	c->point_size = 1.0f;
	c->line_width = 1.0f;
	c->clear_depth = 1.0f;
	c->depth_range_near = 0.0f;
	c->depth_range_far = 1.0f;
	make_viewport_matrix(c->vp_mat, {0, 0}, {s->w, s->h}, 1);
	c->provoking_vert = GL_LAST_VERTEX_CONVENTION;
	c->cull_mode = GL_BACK;
	c->cull_face = GL_FALSE;
	c->front_face = GL_CCW;
	c->depth_test = GL_FALSE;
	c->fragdepth_or_discard = GL_FALSE;
	c->depth_clamp = GL_FALSE;
	c->depth_mask = GL_TRUE;
	c->blend = GL_FALSE;
	c->logic_ops = GL_FALSE;
	c->poly_offset = GL_FALSE;
	c->scissor_test = GL_FALSE;
	c->stencil_test = GL_FALSE;
	set_next_vars(c, s);
}
