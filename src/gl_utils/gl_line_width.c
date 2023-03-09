/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_line_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:14:36 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 15:15:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	gl_line_width(t_GLContext *c, t_gl_float width)
{
	if (width <= 0.0f)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	c->line_width = width;
}
