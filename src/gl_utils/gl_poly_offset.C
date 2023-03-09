/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_poly_offset.C                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:17:48 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 15:21:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_polygon_offset(t_GLContext *c, t_gl_float factor, t_gl_float units)
{
	c->poly_factor = factor;
	c->poly_units = units;
}