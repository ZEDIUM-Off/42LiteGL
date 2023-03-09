/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_polygon_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:03:49 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 15:09:34 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	poly_point_mode(t_GLContext *c, t_gl_enum face, t_gl_enum mode)
{
	if (face == GL_FRONT)
	{
		c->poly_mode_front = mode;
		c->draw_triangle_front = draw_triangle_point;
	}
	else if (face == GL_BACK)
	{
		c->poly_mode_back = mode;
		c->draw_triangle_back = draw_triangle_point;
	}
	else
	{
		c->poly_mode_front = mode;
		c->poly_mode_back = mode;
		c->draw_triangle_front = draw_triangle_point;
		c->draw_triangle_back = draw_triangle_point;
	}
}

void	poly_line_mode(t_GLContext *c, t_gl_enum face, t_gl_enum mode)
{
	if (face == GL_FRONT)
	{
		c->poly_mode_front = mode;
		c->draw_triangle_front = draw_triangle_line;
	}
	else if (face == GL_BACK)
	{
		c->poly_mode_back = mode;
		c->draw_triangle_back = draw_triangle_line;
	}
	else
	{
		c->poly_mode_front = mode;
		c->poly_mode_back = mode;
		c->draw_triangle_front = draw_triangle_line;
		c->draw_triangle_back = draw_triangle_line;
	}
}

void	poly_fill_mode(t_GLContext *c, t_gl_enum face, t_gl_enum mode)
{
	if (face == GL_FRONT)
	{
		c->poly_mode_front = mode;
		c->draw_triangle_front = draw_triangle_fill;
	}
	else if (face == GL_BACK)
	{
		c->poly_mode_back = mode;
		c->draw_triangle_back = draw_triangle_fill;
	}
	else
	{
		c->poly_mode_front = mode;
		c->poly_mode_back = mode;
		c->draw_triangle_front = draw_triangle_fill;
		c->draw_triangle_back = draw_triangle_fill;
	}
}

void	gl_polygon_mode(t_GLContext *c, t_gl_enum face, t_gl_enum mode)
{
	if ((face != GL_FRONT && face != GL_BACK && face != GL_FRONT_AND_BACK)
		|| (mode != GL_POINT && mode != GL_LINE && mode != GL_FILL))
	{
		if (!c->error)
			c->error = GL_INVALID_ENUM;
		return ;
	}
	if (mode == GL_POINT)
		poly_point_mode(c, face, mode);
	else if (mode == GL_LINE)
		poly_line_mode(c, face, mode);
	else
		poly_fill_mode(c, face, mode);
}
