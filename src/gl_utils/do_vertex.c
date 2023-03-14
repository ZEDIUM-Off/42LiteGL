/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_vertex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:11:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 18:22:47 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	do_vertex(
	t_gl_context *c, t_vertex_stage_vars *vars,
	unsigned int i, unsigned int vert)
{
	t_u8			*buf_pos;
	t_vec4			tmpvec4;
	unsigned int	j;

	j = 0;
	while (j < vars->num_enabled)
	{
		buf_pos = (t_u8 *)c->buffers.a[vars->v[vars->enabled[j]].buf].data
			+ vars->v[vars->enabled[j]].offset
			+ vars->v[vars->enabled[j]].stride * i;
		set_vec4(&tmpvec4, new_float4(0.0f, 0.0f, 0.0f, 1.0f));
		ft_memcpy(&tmpvec4, buf_pos, sizeof(float)
			* vars->v[vars->enabled[j]].size);
		c->vertex_attribs_vs[vars->enabled[j]] = tmpvec4;
	}
	c->programs.a[c->cur_program].vertex_shader(&c->vs_output.output_buf.a[vert
			* c->vs_output.size], c->vertex_attribs_vs, &c->builtins,
		c->programs.a[c->cur_program].uniform);
	c->glverts.a[vert].vs_out = &c->vs_output.output_buf.a[vert
		* c->vs_output.size];
	c->glverts.a[vert].clip_space = c->builtins.gl_position;
	c->glverts.a[vert].edge_flag = 1;
	c->glverts.a[vert].clip_code = gl_clipcode(c, c->builtins.gl_position);
}
