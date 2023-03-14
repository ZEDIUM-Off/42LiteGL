/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stencil_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:02:55 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 17:51:59 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	*def_op(t_gl_context *c, int stencil, int depth)
{
	int			op;
	int			ref;
	int			mask;
	t_gl_enum	*ops;

	ops = &c->stencil_sfail_back;
	ref = c->stencil_ref_back;
	mask = c->stencil_writemask_back;
	if (c->builtins.gl_front_facing)
	{
		ops = &c->stencil_sfail;
		ref = c->stencil_ref;
		mask = c->stencil_writemask;
	}
	if (!stencil)
		op = ops[0];
	else
	{
		op = ops[2];
		if (!depth)
			op = ops[1];
	}
	return (new_int3(op, ref, mask));
}

void	set_vars(t_gl_context *c, int *ref, int *mask, int *func)
{
	*func = c->stencil_func_back;
	*ref = c->stencil_ref_back;
	*mask = c->stencil_valuemask_back;
	if (c->builtins.gl_front_facing)
	{
		*func = c->stencil_func;
		*ref = c->stencil_ref;
		*mask = c->stencil_valuemask;
	}
}

int	stencil_test(t_gl_context *c, t_u8 stencil)
{
	int	func;
	int	ref;
	int	mask;

	set_vars(c, &ref, &mask, &func);
	if (func == GL_NEVER)
		return (0);
	else if (func == GL_LESS)
		return ((ref & mask) < (stencil & mask));
	else if (func == GL_LEQUAL)
		return ((ref & mask) <= (stencil & mask));
	else if (func == GL_GREATER)
		return ((ref & mask) > (stencil & mask));
	else if (func == GL_GEQUAL)
		return ((ref & mask) >= (stencil & mask));
	else if (func == GL_EQUAL)
		return ((ref & mask) == (stencil & mask));
	else if (func == GL_NOTEQUAL)
		return ((ref & mask) != (stencil & mask));
	else if (func == GL_ALWAYS)
		return (1);
	return (0);
}

void	stencil_op(t_gl_context *c, int stencil, int depth, t_u8 *dest)
{
	t_u8	val;
	int		*res;

	res = def_op(c, stencil, depth);
	val = *dest;
	if (res[0] == GL_KEEP)
		return ;
	else if (res[0] == GL_ZERO)
		val = 0;
	else if (res[0] == GL_REPLACE)
		val = res[1];
	else if (res[0] == GL_INCR && val < 255)
		val++;
	else if (res[0] == GL_INCR_WRAP)
		val++;
	else if (res[0] == GL_DECR && val > 0)
		val--;
	else if (res[0] == GL_DECR_WRAP)
		val--;
	else if (res[0] == GL_INVERT)
		val = ~val;
	*dest = val & res[2];
}
