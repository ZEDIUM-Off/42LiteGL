/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_context.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:57:55 by  mchenava         #+#    #+#             */
/*   Updated: 2024/02/13 12:33:44 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_CONTEXT_H
# define GL_CONTEXT_H

# include <lite_gl.h>

void	free_cvec(t_gl_context *c);
void	free_gl_context(t_gl_context *c);
int		init_gl_context(t_gl_context *c, t_context_settings setts);
int		alloc_zbuf(t_gl_context *c, t_context_settings *setts);
int		alloc_sten_buf(t_gl_context *c, t_context_settings *setts);
int		init_img_context(t_gl_context *c, t_context_settings *setts);
void	set_bufs(t_gl_context *c, t_context_settings *s);
void	set_text(t_gl_context *c);
void	set_cvec(t_gl_context *c);
void	set_context_vars(t_gl_context *c, t_context_settings *s);
void	set_last_vars(t_gl_context *c, t_context_settings *s);
void	set_next_vars(t_gl_context *c, t_context_settings *s);
void	default_vs(float *vs_output, void *vertex_attribs,
			t_shader_builtins *builtins, void *uniforms);
void	default_fs(float *fs_input, t_shader_builtins *builtins,
			void *uniforms);

#endif
