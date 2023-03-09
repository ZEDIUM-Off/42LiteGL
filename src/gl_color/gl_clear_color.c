/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_clear_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:18:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 12:19:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_clear_color(t_GLContext *c, t_gl_clampf *color)
{
	c->clear_color = vec4_to_color({color[0], color[1], color[2], color[3]});
}
