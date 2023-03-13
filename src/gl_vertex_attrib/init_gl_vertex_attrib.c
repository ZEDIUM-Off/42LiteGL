/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gl_vertex_attrib.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:26:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 15:26:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	init_gl_vertex_attrib(t_gl_vertex_attrib *v)
{
	v->buf = 0;
	v->enabled = 0;
	v->divisor = 0;
}
