/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_ops_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:05:46 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 18:07:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_color	lop2(t_gl_context *c, t_color s, t_color d)
{
	if (c->logic_func == GL_XOR)
		return (make_color(s.r ^ d.r, s.g ^ d.g, s.b ^ d.b, s.a ^ d.a));
	if (c->logic_func == GL_EQUIV)
		return (make_color(~(s.r ^ d.r), ~(s.g ^ d.g),
				~(s.b ^ d.b), ~(s.a ^ d.a)));
	if (c->logic_func == GL_AND_REVERSE)
		return (make_color(s.r & ~d.r, s.g & ~d.g, s.b & ~d.b, s.a & ~d.a));
	if (c->logic_func == GL_AND_INVERTED)
		return (make_color(~s.r & d.r, ~s.g & d.g, ~s.b & d.b, ~s.a & d.a));
	if (c->logic_func == GL_OR_REVERSE)
		return (make_color(s.r | ~d.r, s.g | ~d.g, s.b | ~d.b, s.a | ~d.a));
	if (c->logic_func == GL_OR_INVERTED)
		return (make_color(~s.r | d.r, ~s.g | d.g, ~s.b | d.b, ~s.a | d.a));
	return (s);
}

t_color	logic_ops_pixel(t_gl_context *c, t_color s, t_color d)
{
	if (c->logic_func == GL_CLEAR)
		return (make_color(0, 0, 0, 0));
	if (c->logic_func == GL_SET)
		return (make_color(255, 255, 255, 255));
	if (c->logic_func == GL_COPY)
		return (s);
	if (c->logic_func == GL_COPY_INVERTED)
		return (make_color(~s.r, ~s.g, ~s.b, ~s.a));
	if (c->logic_func == GL_NOOP)
		return (d);
	if (c->logic_func == GL_INVERT)
		return (make_color(~d.r, ~d.g, ~d.b, ~d.a));
	if (c->logic_func == GL_AND)
		return (make_color(s.r & d.r, s.g & d.g, s.b & d.b, s.a & d.a));
	if (c->logic_func == GL_NAND)
		return (make_color(~(s.r & d.r), ~(s.g & d.g),
				~(s.b & d.b), ~(s.a & d.a)));
	if (c->logic_func == GL_OR)
		return (make_color(s.r | d.r, s.g | d.g, s.b | d.b, s.a | d.a));
	if (c->logic_func == GL_NOR)
		return (make_color(~(s.r | d.r), ~(s.g | d.g),
				~(s.b | d.b), ~(s.a | d.a)));
	return (lop2(c, s, d));
}
