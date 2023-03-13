/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgl_set_uniform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:22:01 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 12:44:15 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	lgl_set_uniform(t_gl_context *c, void *uniform)
{
	if (!c->cur_program)
		return ;
	if (!uniform)
		return ;
	c->programs.a[c->cur_program].uniform = uniform;
}
