/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_get_integerv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:40:11 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 16:03:49 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	get_integerv_part1(t_gl_context *c, t_gl_enum pname, t_gl_int *params)
{
	if (pname == GL_STENCIL_WRITE_MASK)
		return (params[0] = c->stencil_writemask, 1);
	else if (pname == GL_STENCIL_REF)
		return (params[0] = c->stencil_ref, 1);
	else if (pname == GL_STENCIL_VALUE_MASK)
		return (params[0] = c->stencil_valuemask, 1);
	else if (pname == GL_STENCIL_FUNC)
		return (params[0] = c->stencil_func, 1);
	else if (pname == GL_STENCIL_FAIL)
		return (params[0] = c->stencil_sfail, 1);
	else if (pname == GL_STENCIL_PASS_DEPTH_FAIL)
		return (params[0] = c->stencil_dpfail, 1);
	else if (pname == GL_STENCIL_PASS_DEPTH_PASS)
		return (params[0] = c->stencil_dppass, 1);
	else if (pname == GL_STENCIL_BACK_WRITE_MASK)
		return (params[0] = c->stencil_writemask_back, 1);
	else if (pname == GL_STENCIL_BACK_REF)
		return (params[0] = c->stencil_ref_back, 1);
	else if (pname == GL_STENCIL_BACK_VALUE_MASK)
		return (params[0] = c->stencil_valuemask_back, 1);
	else if (pname == GL_STENCIL_BACK_FUNC)
		return (params[0] = c->stencil_func_back, 1);
	else if (pname == GL_STENCIL_BACK_FAIL)
		return (params[0] = c->stencil_sfail_back, 1);
	return (0);
}

int	get_integerv_part2(t_gl_context *c, t_gl_enum pname, t_gl_int *params)
{
	if (pname == GL_STENCIL_BACK_PASS_DEPTH_FAIL)
		return (params[0] = c->stencil_dpfail_back, 1);
	else if (pname == GL_STENCIL_BACK_PASS_DEPTH_PASS)
		return (params[0] = c->stencil_dppass_back, 1);
	else if (pname == GL_LOGIC_OP_MODE)
		return (params[0] = c->logic_func, 1);
	else if (pname == GL_BLEND_SRC_RGB)
		return (1);
	else if (pname == GL_BLEND_SRC_ALPHA)
		return (params[0] = c->blend_sfactor, 1);
	else if (pname == GL_BLEND_DST_RGB)
		return (1);
	else if (pname == GL_BLEND_DST_ALPHA)
		return (params[0] = c->blend_dfactor, 1);
	else if (pname == GL_BLEND_EQUATION_RGB)
		return (1);
	else if (pname == GL_BLEND_EQUATION_ALPHA)
		return (params[0] = c->blend_equation, 1);
	else if (pname == GL_CULL_FACE_MODE)
		return (params[0] = c->cull_mode, 1);
	else if (pname == GL_FRONT_FACE)
		return (params[0] = c->front_face, 1);
	else if (pname == GL_DEPTH_FUNC)
		return (params[0] = c->depth_func, 1);
	return (0);
}

int	get_integerv_part3(t_gl_context *c, t_gl_enum pname, t_gl_int *params)
{
	if (pname == GL_POINT_SPRITE_COORD_ORIGIN)
		return (params[0] = c->point_spr_origin, 1);
	else if (pname == GL_PROVOKING_VERTEX)
		return (params[0] = c->provoking_vert, 1);
	else if (pname == GL_POLYGON_MODE)
		return (params[0] = c->poly_mode_front,
			params[1] = c->poly_mode_back, 1);
	else if (pname == GL_MAJOR_VERSION)
		return (params[0] = 3, 1);
	else if (pname == GL_MINOR_VERSION)
		return (params[0] = 2, 1);
	else if (pname == GL_TEXTURE_BINDING_1D)
		return (params[0] = c->bound_textures[
				GL_TEXTURE_1D - GL_TEXTURE_UNBOUND - 1], 1);
	else if (pname == GL_TEXTURE_BINDING_2D)
		return (params[0] = c->bound_textures[
				GL_TEXTURE_2D - GL_TEXTURE_UNBOUND - 1], 1);
	else if (pname == GL_TEXTURE_BINDING_3D)
		return (params[0] = c->bound_textures[
				GL_TEXTURE_3D - GL_TEXTURE_UNBOUND - 1], 1);
	else if (pname == GL_TEXTURE_BINDING_1D_ARRAY)
		return (params[0] = c->bound_textures[
				GL_TEXTURE_1D_ARRAY - GL_TEXTURE_UNBOUND - 1], 1);
	return (0);
}

int	get_integerv_part4(t_gl_context *c, t_gl_enum pname, t_gl_int *params)
{
	if (pname == GL_TEXTURE_BINDING_2D_ARRAY)
		return (params[0] = c->bound_textures[
				GL_TEXTURE_2D_ARRAY - GL_TEXTURE_UNBOUND - 1], 1);
	else if (pname == GL_TEXTURE_BINDING_RECTANGLE)
		return (params[0] = c->bound_textures[
				GL_TEXTURE_RECTANGLE - GL_TEXTURE_UNBOUND - 1], 1);
	else if (params[0] == GL_TEXTURE_BINDING_CUBE_MAP)
		return (params[0] = c->bound_textures[
				GL_TEXTURE_CUBE_MAP - GL_TEXTURE_UNBOUND - 1], 1);
	return (0);
}

void	gl_get_integerv(t_gl_context *c, t_gl_enum pname, t_gl_int *params)
{
	if (!get_integerv_part1(c, pname, params))
		if (!get_integerv_part2(c, pname, params))
			if (!get_integerv_part3(c, pname, params))
				if (!get_integerv_part4(c, pname, params) && !c->error)
					c->error = GL_INVALID_ENUM;
}
