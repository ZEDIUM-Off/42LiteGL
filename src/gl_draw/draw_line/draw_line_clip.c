/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_clip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:02:37 by  mchenava         #+#    #+#             */
/*   Updated: 2023/02/28 12:49:09 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

static void	thikness_choice(t_GLContext *c, t_vec4 *traces, float **v_out,
	unsigned int provoke)
{
	if (c->line_width < 1.5f)
		draw_line_shader(c, traces, v_out, provoke);
	else
		draw_thick_line_shader(c, traces, v_out, provoke);
}

static void	interpolate_clipped_line(glVertex	**vertexes,
	float **v_out, float *tmin_max)
{
	int	i;

	i = 0;
	while (i < c->vs_output.size)
	{
		v_out[0][i] = vertexes[0]->vs_out[i] + (vertexes[1]->vs_out[i]
				- vertexes[0]->vs_out[i]) * tmin_max[0];
		v_out[1][i] = vertexes[0]->vs_out[i] + (vertexes[1]->vs_out[i]
				- vertexes[0]->vs_out[i]) * tmin_max[1];
		i++;
	}
}

void	clip_and_draw_line(t_GLContext *c, t_glVertex **vertexes,
	t_vec4 *traces, unsigned int provoke)
{
	float	v_out[2][GL_MAX_VERTEX_OUTPUT_COMPONENTS];
	t_vec4	diff;
	float	t[2];
	t_vec4	cs[2];

	cs = {vertexes[0]->clip_space, vertexes[1]->clip_space};
	diff = sub_vec4s(cs[1], cs[0]);
	t[0] = 0;
	t[1] = 1;
	if (
		clip_line(diff.x + diff.w, -cs[0].x - cs[0].w, &t[0], &t[1])
		&& clip_line(-diff.x + diff.w, cs[0].x - cs[0].w, &t[0], &t[1])
		&& clip_line(diff.y + diff.w, -cs[0].y - cs[0].w, &t[0], &t[1])
		&& clip_line(-diff.y + diff.w, cs[0].y - cs[0].w, &t[0], &t[1])
		&& clip_line(diff.z + diff.w, -cs[0].z - cs[0].w, &t[0], &t[1])
		&& clip_line(-diff.z + diff.w, cs[0].z - cs[0].w, &t[0], &t[1]))
	{
		traces[0] = add_vec4s(cs[0], scale_vec4(diff, t[0]));
		traces[1] = add_vec4s(cs[0], scale_vec4(diff, t[1]));
		traces[0] = mult_mat4_vec4(c->vp_mat, traces[0]);
		traces[1] = mult_mat4_vec4(c->vp_mat, traces[1]);
		interpolate_clipped_line(vertexes, v_out, t);
		thikness_choice(c, traces, {vertexes[0]->vs_out,
			vertexes[1]->vs_out}, provoke);
	}
}

void	draw_line_clip(t_GLContext *c, t_glVertex *v1, t_glVextex *v2)
{
	t_vec4			traces[2];
	unsigned int	provoke;

	provoke = (v1 - c->glverts.a) / sizeof(t_glVertex);
	if (c->provoking_vert == GL_LAST_VERTEX_CONVENTION)
		provoke = (v2 - c->glverts.a) / sizeof(t_glVertex);
	if (v1->clip_code & v2->clip_code)
		return ;
	else if ((v1->clip_code | v2->clip_code) == 0)
	{
		traces[0] = mult_mat4_vec4(c->vp_mat, cs[0]);
		traces[1] = mult_mat4_vec4(c->vp_mat, v2->clip_space);
		thikness_choice(c, traces, {v1->vs_out, v2->vs_out}, provoke);
	}
	else
		clip_and_draw_line(c, {v1, v2}, traces, provoke);
}
