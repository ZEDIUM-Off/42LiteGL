/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:14:52 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 12:17:43 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_line	make_line(float x1, float y1, float x2, float y2)
{
	t_line	line;

	line.a = y1 - y2;
	line.b = x2 - x1;
	line.c = x1 * y2 - x2 * y1;
	return (line);
}

float	line_func(t_line	*line, float x, float y)
{
	return (line->a * x + line->b * y + line->c);
}

float	line_findy(t_line *line, float x)
{
	return (-(line->a * x + line->c) / line->b);
}

float	line_findx(t_line *line, float y)
{
	return (-(line->b * y + line->c) / line->a);
}
