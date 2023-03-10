/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_clear_stencil.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:16:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/10 09:17:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_clear_stencil(t_GLContext *c, t_gl_int s)
{
	c->stencil_clear_value = s & 0xFF;
}
