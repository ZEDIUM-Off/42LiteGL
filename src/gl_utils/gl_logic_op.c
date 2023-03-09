/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_logic_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:16:40 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 15:17:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	gl_logic_op(t_GLContext *c, t_gl_enum opcode)
{
	if (opcode < GL_CLEAR || opcode > GL_INVERT)
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	c->logic_func = opcode;
}
