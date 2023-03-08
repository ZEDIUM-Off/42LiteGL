/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_line.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:02:18 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 12:02:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_LINE_H
# define GL_LINE_H

# include <lite_gl.h>

t_line	make_line(float x1, float y1, float x2, float y2);
float	line_func(t_line	*line, float x, float y);
float	line_findy(t_line *line, float x);
float	line_findx(t_line *line, float y);

#endif