/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_shader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:35:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/25 14:23:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	set_interpol(
	t_gl_program	*prog, t_gl_sizei n, t_gl_enum *interpolation)
{
	int	i;

	i = 0;
	while (i < n)
	{
		prog->interpolation[i] = interpolation[i];
		i++;
	}
}

void	lgl_set_uniform(t_gl_context *c, void *uniform)
{
	c->programs.a[c->cur_program].uniform = uniform;
}

t_gl_uint	lgl_create_program(
	t_gl_context *c, t_gl_program prog_attr, t_gl_enum *tmp_interpolation)
{
	t_gl_program	tmp;
	size_t			i;

	if (!prog_attr.vertex_shader || !prog_attr.fragment_shader)
		return (0);
	if (prog_attr.vs_output_size > GL_MAX_VERTEX_OUTPUT_COMPONENTS)
		return ((set_err(c, GL_INVALID_ENUM)), 0);
	tmp = (t_gl_program) \
	{prog_attr.vertex_shader, prog_attr.fragment_shader, NULL, \
	prog_attr.vs_output_size, {0}, prog_attr.fragdepth_or_discard, GL_FALSE};
	set_interpol(&tmp, prog_attr.vs_output_size, tmp_interpolation);
	i = 1;
	while (i < c->programs.size)
	{
		if (c->programs.a[i].deleted && i != c->cur_program)
		{
			c->programs.a[i] = tmp;
			return (i);
		}
		i++;
	}
	return (cvec_push_gl_program(&c->programs, tmp), c->programs.size - 1);
}

void	gl_use_program(t_gl_context *c, t_gl_uint program)
{
	if (program >= c->programs.size)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	c->vs_output.size = c->programs.a[program].vs_output_size;
	cvec_reserve_float(&c->vs_output.output_buf,
		c->vs_output.size * MAX_VERTICES);
	c->vs_output.interpolation = c->programs.a[program].interpolation;
	c->fragdepth_or_discard = c->programs.a[program].fragdepth_or_discard;
	c->cur_program = program;
}

void	gl_delete_program(t_gl_context *c, t_gl_uint program)
{
	if (!program)
		return ;
	if (program >= c->programs.size)
	{
		if (!c->error)
			c->error = GL_INVALID_VALUE;
		return ;
	}
	c->programs.a[program].deleted = GL_TRUE;
}
