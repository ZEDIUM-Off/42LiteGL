/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle_clip.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:11:13 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/01 14:53:15 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	up_clip(t_draw_tri_clip_vars	*vars)
{
	vars->tt = clip_proc[clip_bit](
			&vars->tmp1.clip_space, &vars->new_v[0].clip_space,
			&vars->new_v[1].clip_space);
	update_clip_pt(&vars->tmp1, vars->new_v[0], vars->new_v[1], vars->tt);
	vars->tt = clip_proc[clip_bit](
			&vars->tmp2.clip_space, &vars->new_v[0].clip_space,
			&vars->new_v[2].clip_space);
	update_clip_pt(&vars->tmp2, vars->new_v[0], vars->new_v[2], vars->tt);
}

void	draw_tri_clip_one_pt_out(
	t_GLContext *c, t_glVertex **v, unsigned int provoke, int clip_bit)
{
	t_draw_tri_clip_vars	vars;

	set_draw_tri_clip_vars(&vars);
	if (v[0]->clip_code & (1 << clip_bit))
		vars.new_v = {v[0], v[1], v[2]};
	else if (v[1]->clip_code & (1 << clip_bit))
		vars.new_v = {v[1], v[2], v[0]};
	else
		vars.new_v = {v[2], v[0], v[1]};
	up_clip(&vars);
	vars.tmp1.edge_flag = new_v[0].edge_flag;
	vars.edge_flag_tmp = new_v[2].edge_flag;
	vars.new_v[2].edge_flag = 0;
	draw_triangle_clip(c,
	{&vars.tmp1, vars.new_v[1], vars.new_v[2]}, provoke, clip_bit + 1);
	vars.tmp2.edge_flag = 1;
	vars.tmp1.edge_flag = 0;
	vars.new_v[2].edge_flag = vars.edge_flag_tmp;
	draw_triangle_clip(c,
	{&vars.tmp2, &vars.tmp1, vars.new_v[2]}, provoke, clip_bit + 1);
}

void	draw_tri_clip_two_pts_out(
	t_GLContext *c, t_glVertex **v, unsigned int provoke, int clip_bit)
{
	t_draw_tri_clip_vars	vars;

	set_draw_tri_clip_vars(&vars);
	if ((v[0]->clip_code & (1 << clip_bit)) == 0)
		vars.new_v = {v[0], v[1], v[2]};
	else if ((v[1]->clip_code & (1 << clip_bit)) == 0)
		vars.new_v = {v[1], v[2], v[0]};
	else
		vars.new_v = {v[2], v[0], v[1]};
	up_clip(&vars);
	vars.tmp1.edge_flag = 1;
	vars.tmp2.edge_flag = vars.new_v[2].edge_flag;
	draw_triangle_clip(c,
	{vars.new_v[0], &vars.tmp1, &vars.tmp2}, provoke, clip_bit + 1);
}

void	draw_triangle_clip(
	t_GLContext *c, t_glVertex **v, unsigned int provoke, int clip_bit)
{
	if (v[0]->clip_code | v[1]->clip_code | v[2]->clip_code == 0)
		draw_triangle_final(c, v, provoke);
	else
	{
		if (v[0]->clip_code & v[1]->clip_code & v[2]->clip_code != 0)
			return ;
		while (clip_bit < 6
			&& ((v[0]->clip_code | v[1]->clip_code | v[2]->clip_code == 0)
				& (1 << clip_bit)) == 0)
			++clip_bit;
		if (clip_bit == 6)
			return ;
		if ((v[0]->clip_code ^ v[1]->clip_code ^ v[2]->clip_code)
			& (1 << clip_bit))
			draw_tri_clip_one_pt_out(c, v, provoke, clip_bit);
		else
			draw_tri_clip_two_pts_out(c, v, provoke, clip_bit);
	}
}
