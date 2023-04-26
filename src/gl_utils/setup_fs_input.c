/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fs_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:17:27 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/24 10:51:13 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	setup_fs_input(
	t_gl_context *c, float **vs_out,
	t_draw_line_shader_vars *v, unsigned int provoke)
{
	float	*vs_output;
	int		i;

	vs_output = &c->vs_output.output_buf.a[0];
	i = 0;
	while (i < c->vs_output.size)
	{
		if (c->vs_output.interpolation[i] == SMOOTH)
			c->fs_input[i] = (vs_out[0][i] * (1 / v->w[0]) + v->t
					* (vs_out[1][i] * (1 / v->w[1]) - vs_out[0][i]
						* (1 / v->w[0]))) / ((1 / v->w[0]) + v->t
					* ((1 / v->w[1]) - (1 / v->w[0])));
		else if (c->vs_output.interpolation[i] == NOPERSPECTIVE)
			c->fs_input[i] = vs_out[0][i] + v->t
				* (vs_out[1][i] - vs_out[0][i]);
		else
			c->fs_input[i] = vs_output[provoke * c->vs_output.size + i];
		i++;
	}
	c->builtins.discard = GL_FALSE;
}
