/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:04:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/11 15:17:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	default_vs(
	float *vs_output, void *vertex_attribs,
	t_shader_builtins *builtins, void *uniforms)
{
	(void)vs_output;
	(void)uniforms;
	builtins->gl_position = ((t_vec4 *)vertex_attribs)[0];
}

void	default_fs(float *fs_input, t_shader_builtins *builtins, void *uniforms)
{
	t_vec4	*fragcolor;

	(void)fs_input;
	(void)uniforms;
	fragcolor = &builtins->gl_frag_color;
	fragcolor->x = 1.0f;
	fragcolor->y = 0.0f;
	fragcolor->z = 0.0f;
	fragcolor->w = 1.0f;
}

int	init_gl_context(t_gl_context *c, t_context_settings setts)
{
	if (!init_img_context(c, &setts))
		return (0);
	set_context_vars(c, &setts);
	init_clip_proc(c);
	return (1);
}
