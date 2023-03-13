/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_clear_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:18:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 14:51:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_clear_color(t_gl_context *c, t_gl_clampf *color)
{
	t_vec4	vcol;

	vcol = (t_vec4){color[0], color[1], color[2], color[3]};
	c->clear_color = vec4_to_color(vcol);
}
