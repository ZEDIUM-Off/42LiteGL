/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_stage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:08 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/04 12:22:17 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	first_part(
	t_gl_context *c, t_pipeline_settings *sett, t_vertex_stage_vars *vars)
{
	while (vars->i < GL_MAX_VERTEX_ATTRIBS)
	{
		if (vars->v[vars->i].enabled)
		{
			if (vars->v[vars->i].divisor == 0)
				vars->enabled[vars->num_enabled++] = vars->i;
			else if (!(sett->instance % vars->v[vars->i].divisor))
			{
				ft_memcpy(&c->vertex_attribs_vs[vars->i],
					vars->vec4_init, sizeof(t_vec4));
				vars->n = sett->instance
					/ vars->v[vars->i].divisor + sett->base_instance;
				vars->buf_pos = (t_u8 *)c->buffers.a[
					vars->v[vars->i].buf].data + vars->v[vars->i].offset
					+ vars->v[vars->i].stride * vars->n;
				ft_memcpy(&c->vertex_attribs_vs[vars->i], vars->buf_pos,
					sizeof(float) * vars->v[vars->i].size);
			}
		}
		vars->i++;
	}
}

void	second_part(
	t_gl_context *c, t_pipeline_settings *sett, t_vertex_stage_vars *vars)
{
	vars->vert = 0;
	vars->i = sett->first;
	while (vars->i < sett->first + sett->count)
	{
		if (!sett->use_elements)
			do_vertex(c, vars, vars->i, vars->vert);
		else
		{
			if (c->buffers.a[vars->elem_buffer].type == GL_UNSIGNED_BYTE)
				do_vertex(c, vars, vars->ubyte_array[vars->i], vars->vert);
			else if (c->buffers.a[vars->elem_buffer].type == GL_UNSIGNED_SHORT)
				do_vertex(c, vars, vars->ushort_array[vars->i], vars->vert);
			else if (c->buffers.a[vars->elem_buffer].type == GL_UNSIGNED_INT)
				do_vertex(c, vars, vars->uint_array[vars->i], vars->vert);
		}
		vars->i++;
		vars->vert++;
	}
}

	// if (!sett->use_elements)
	// 	while (vars->i < sett->first + sett->count)
	// 		do_vertex(c, vars, vars->i++, vars->vert++);
	// else
	// {
	// 	if (c->buffers.a[vars->elem_buffer].type == GL_UNSIGNED_BYTE)
	// 		while (vars->i < sett->first + sett->count)
	// 			do_vertex(c, vars, vars->ubyte_array[vars->i++], vars->vert++);
	// 	else if (c->buffers.a[vars->elem_buffer].type == GL_UNSIGNED_SHORT)
	// 		while (vars->i < sett->first + sett->count)
	// 			do_vertex(c, vars, vars->ushort_array[vars->i++], vars->vert++);
	// 	else if (c->buffers.a[vars->elem_buffer].type == GL_UNSIGNED_INT)
	// 		while (vars->i < sett->first + sett->count)
	// 			do_vertex(c, vars, vars->uint_array[vars->i++], vars->vert++);
	// }

void	vertex_stage(t_gl_context *c, t_pipeline_settings *sett)
{
	static t_vertex_stage_vars	vars;

	vars.vec4_init = (float [4]){0, 0, 0, 1};
	vars.v = c->vertex_arrays.a[c->cur_vertex_array].vertex_attribs;
	vars.elem_buffer = c->vertex_arrays.a[c->cur_vertex_array].element_buffer;
	vars.i = 0;
	vars.num_enabled = 0;
	first_part(c, sett, &vars);
	cvec_reserve_gl_vertex(&c->glverts, sett->count);
	c->builtins.gl_instance_id = sett->instance;
	vars.uint_array = (t_gl_uint *)c->buffers.a[vars.elem_buffer].data;
	vars.ushort_array = (t_gl_ushort *)c->buffers.a[vars.elem_buffer].data;
	vars.ubyte_array = (t_gl_ubyte *)c->buffers.a[vars.elem_buffer].data;
	second_part(c, sett, &vars);
}
