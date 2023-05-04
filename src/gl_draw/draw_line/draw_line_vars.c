/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:16:10 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/04 12:28:35 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	left_right(t_draw_line_shader_vars *vars, float **v_out)
{
	float	tmp;
	float	*tmp_ptr;

	if (vars->x[0] > vars->x[1])
	{
		tmp = vars->x[0];
		vars->x[0] = vars->x[1];
		vars->x[1] = tmp;
		tmp = vars->y[0];
		vars->y[0] = vars->y[1];
		vars->y[1] = tmp;
		tmp = vars->z[0];
		vars->z[0] = vars->z[1];
		vars->z[1] = tmp;
		tmp = vars->w[0];
		vars->w[0] = vars->w[1];
		vars->w[1] = tmp;
		tmp_ptr = v_out[0];
		v_out[0] = v_out[1];
		v_out[1] = tmp_ptr;
	}
}

void	mima_left_right(t_draw_line_shader_vars *vars)
{
	if (vars->slope <= 0)
	{
		vars->y_mima[0] = vars->i_y[1];
		vars->y_mima[1] = vars->i_y[0];
	}
	else
	{
		vars->y_mima[0] = vars->i_y[0];
		vars->y_mima[1] = vars->i_y[1];
	}
}

t_vec2	set_ab(t_gl_context *c, t_draw_line_shader_vars *vars)
{
	t_vec2	ab;

	ab = init_vec2(vars->line.a, vars->line.b);
	normalize_vec2(&ab);
	ab = scale_vec2s(ab, c->line_width / 2);
	return (ab);
}

void	set_line_shader_vars(t_gl_context *c, t_draw_line_shader_vars *vars,
	t_vec4 *vertexes, float v_out[2][2])
{
	t_vec3	*hp;

	hp = (t_vec3 [2]){vec4_to_vec3h(vertexes[0]), vec4_to_vec3h(vertexes[1])};
	vars->x = (float [2]){hp[0].x, hp[1].x};
	vars->y = (float [2]){hp[0].y, hp[1].y};
	vars->z = (float [2]){hp[0].z, hp[1].z};
	vars->w = (float [2]){vertexes[0].w, vertexes[1].w};
	left_right(vars, (float **)v_out);
	vars->slope = (vars->y[1] - vars->y[0]) / (vars->x[1] - vars->x[0]);
	vars->line = make_line(vars->x[0], vars->y[0], vars->x[1], vars->y[1]);
	vars->ab = set_ab(c, vars);
	vars->p[0] = (t_vec2){vars->x[0], vars->y[0]};
	vars->p[1] = (t_vec2){vars->x[1], vars->y[1]};
	vars->sub_p = sub_vec2s(vars->p[1], vars->p[0]);
	vars->line_len_sq = vec2_lenght(vars->sub_p);
	vars->line_len_sq *= vars->line_len_sq;
	vars->i_x[0] = floor(vars->p[0].x) + 0.5;
	vars->i_x[1] = floor(vars->p[1].x) + 0.5;
	vars->i_y[0] = floor(vars->p[0].y) + 0.5;
	vars->i_y[1] = floor(vars->p[1].y) + 0.5;
	vars->x_mima[0] = vars->i_x[0];
	vars->x_mima[1] = vars->i_x[1];
	mima_left_right(vars);
	vars->z[0] = map(vars->z[0], c->depth_range_near, c->depth_range_far);
	vars->z[1] = map(vars->z[1], c->depth_range_near, c->depth_range_far);
}

void	set_perp_line_vars(
	t_gl_context *c, t_draw_line_shader_vars *vars, float vx[2], float vy[2])
{
	vars->line = make_line(vx[0], vy[0], vx[1], vy[1]);
	vars->i_x[0] = floor(vx[0]) + 0.5;
	vars->i_x[1] = floor(vx[1]) + 0.5;
	vars->i_y[0] = floor(vy[0]) + 0.5;
	vars->i_y[1] = floor(vy[1]) + 0.5;
	vars->x_mima[0] = vars->i_x[0];
	vars->x_mima[1] = vars->i_x[1];
	mima_left_right(vars);
	vars->lz = c->builtins.gl_frag_coord.z;
	vars->lw = c->back_buffer.w;
	vars->lh = c->back_buffer.h;
	vars->first_is_diag = GL_FALSE;
}
