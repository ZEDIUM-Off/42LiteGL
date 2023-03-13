/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:04:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 15:56:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	default_vs(void *vertex_attribs,
	t_shader_builtins *builtins)
{
	builtins->gl_position = ((t_vec4 *)vertex_attribs)[0];
}

void	default_fs(t_shader_builtins *builtins)
{
	t_vec4	*fragcolor;

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
	return (1);
}
