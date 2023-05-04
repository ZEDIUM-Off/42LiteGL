/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:41:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/04 12:21:06 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	sfactor_p2(t_gl_context *c, t_vec4 src, t_vec4 dst, t_vec4 *cs)
{
	if (c->blend_sfactor == GL_CONSTANT_ALPHA)
		set_vec4(cs, (float [4]){c->blend_color.w, c->blend_color.w,
			c->blend_color.w, c->blend_color.w});
	else if (c->blend_sfactor == GL_ONE_MINUS_CONSTANT_ALPHA)
		set_vec4(cs, (float [4]){1 - c->blend_color.w, 1 - c->blend_color.w,
			1 - c->blend_color.w, 1 - c->blend_color.w});
	else if (c->blend_sfactor == GL_SRC_ALPHA_SATURATE)
		set_vec4(cs, (float [4]){fmin(src.w, 1 - dst.w), fmin(src.w, 1 - dst.w),
			fmin(src.w, 1 - dst.w), 1});
}

void	sfactor_p1(t_gl_context *c, t_vec4 src, t_vec4 dst, t_vec4 *cs)
{
	if (c->blend_sfactor == GL_ZERO)
		set_vec4(cs, (float [4]){0, 0, 0, 0});
	else if (c->blend_sfactor == GL_ONE)
		set_vec4(cs, (float [4]){1, 1, 1, 1});
	else if (c->blend_sfactor == GL_SRC_COLOR)
		*cs = src;
	else if (c->blend_sfactor == GL_ONE_MINUS_SRC_COLOR)
		set_vec4(cs, (float [4]){1 - src.x, 1 - src.y, 1 - src.z, 1 - src.w});
	else if (c->blend_sfactor == GL_DST_COLOR)
		*cs = dst;
	else if (c->blend_sfactor == GL_ONE_MINUS_DST_COLOR)
		set_vec4(cs, (float [4]){1 - dst.x, 1 - dst.y, 1 - dst.z, 1 - dst.w});
	else if (c->blend_sfactor == GL_SRC_ALPHA)
		set_vec4(cs, (float [4]){src.w, src.w, src.w, src.w});
	else if (c->blend_sfactor == GL_ONE_MINUS_SRC_ALPHA)
		set_vec4(cs, (float [4]){1 - src.w, 1 - src.w, 1 - src.w, 1 - src.w});
	else if (c->blend_sfactor == GL_DST_ALPHA)
		set_vec4(cs, (float [4]){dst.w, dst.w, dst.w, dst.w});
	else if (c->blend_sfactor == GL_ONE_MINUS_DST_ALPHA)
		set_vec4(cs, (float [4]){1 - dst.w, 1 - dst.w, 1 - dst.w, 1 - dst.w});
	else if (c->blend_sfactor == GL_CONSTANT_COLOR)
		*cs = c->blend_color;
	else if (c->blend_sfactor == GL_ONE_MINUS_CONSTANT_COLOR)
		set_vec4(cs, (float [4]){1 - c->blend_color.x, 1 - c->blend_color.y,
			1 - c->blend_color.z, 1 - c->blend_color.w});
}

void	dfactor_p2(t_gl_context *c, t_vec4 src, t_vec4 dst, t_vec4 *cd)
{
	if (c->blend_dfactor == GL_CONSTANT_ALPHA)
		set_vec4(cd, (float [4]){c->blend_color.w, c->blend_color.w,
			c->blend_color.w, c->blend_color.w});
	else if (c->blend_dfactor == GL_ONE_MINUS_CONSTANT_ALPHA)
		set_vec4(cd, (float [4]){1 - c->blend_color.w, 1 - c->blend_color.w,
			1 - c->blend_color.w, 1 - c->blend_color.w});
	else if (c->blend_dfactor == GL_SRC_ALPHA_SATURATE)
		set_vec4(cd, (float [4]){fmin(src.w, 1 - dst.w), fmin(src.w, 1 - dst.w),
			fmin(src.w, 1 - dst.w), 1});
}

void	dfactor_p1(t_gl_context *c, t_vec4 src, t_vec4 dst, t_vec4 *cd)
{
	if (c->blend_dfactor == GL_ZERO)
		set_vec4(cd, (float [4]){0, 0, 0, 0});
	else if (c->blend_dfactor == GL_ONE)
		set_vec4(cd, (float [4]){1, 1, 1, 1});
	else if (c->blend_dfactor == GL_SRC_COLOR)
		*cd = src;
	else if (c->blend_dfactor == GL_ONE_MINUS_SRC_COLOR)
		set_vec4(cd, (float [4]){1 - src.x, 1 - src.y, 1 - src.z, 1 - src.w});
	else if (c->blend_dfactor == GL_DST_COLOR)
		*cd = dst;
	else if (c->blend_dfactor == GL_ONE_MINUS_DST_COLOR)
		set_vec4(cd, (float [4]){1 - dst.x, 1 - dst.y, 1 - dst.z, 1 - dst.w});
	else if (c->blend_dfactor == GL_SRC_ALPHA)
		set_vec4(cd, (float [4]){src.w, src.w, src.w, src.w});
	else if (c->blend_dfactor == GL_ONE_MINUS_SRC_ALPHA)
		set_vec4(cd, (float [4]){1 - src.w, 1 - src.w, 1 - src.w, 1 - src.w});
	else if (c->blend_dfactor == GL_DST_ALPHA)
		set_vec4(cd, (float [4]){dst.w, dst.w, dst.w, dst.w});
	else if (c->blend_dfactor == GL_ONE_MINUS_DST_ALPHA)
		set_vec4(cd, (float [4]){1 - dst.w, 1 - dst.w, 1 - dst.w, 1 - dst.w});
	else if (c->blend_dfactor == GL_CONSTANT_COLOR)
		*cd = c->blend_color;
	else if (c->blend_dfactor == GL_ONE_MINUS_CONSTANT_COLOR)
		set_vec4(cd, (float [4]){1 - c->blend_color.x, 1 - c->blend_color.y,
			1 - c->blend_color.z, 1 - c->blend_color.w});
}

t_color	blend_pixel(t_gl_context *c, t_vec4 src, t_vec4 dst)
{
	t_vec4	cs;
	t_vec4	cd;
	t_vec4	result;

	sfactor_p1(c, src, dst, &cs);
	sfactor_p2(c, src, dst, &cs);
	dfactor_p1(c, src, dst, &cd);
	dfactor_p2(c, src, dst, &cd);
	set_vec4(&result, (float [4]){0, 0, 0, 0});
	if (c->blend_equation == GL_FUNC_ADD)
		result = add_vec4s(mult_vec4s(cs, src), mult_vec4s(cd, dst));
	else if (c->blend_equation == GL_FUNC_SUBTRACT)
		result = sub_vec4s(mult_vec4s(cs, src), mult_vec4s(cd, dst));
	else if (c->blend_equation == GL_FUNC_REVERSE_SUBTRACT)
		result = sub_vec4s(mult_vec4s(cd, dst), mult_vec4s(cs, src));
	else if (c->blend_equation == GL_MIN)
		set_vec4(&result, (float [4]){fmin(src.x, dst.x),
			fmin(src.y, dst.y), fmin(src.z, dst.z), fmin(src.w, dst.w)});
	else if (c->blend_equation == GL_MAX)
		set_vec4(&result, (float [4]){fmax(src.x, dst.x), fmax(src.y, dst.y),
			fmax(src.z, dst.z), fmax(src.w, dst.w)});
	return (vec4_to_color(result));
}
