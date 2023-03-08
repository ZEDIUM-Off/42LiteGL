/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:06:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 12:22:23 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	radians(float degrees)
{
	return (degrees * M_PI / 180.0);
}

float	degrees(float radians)
{
	return (radians * 180.0 / M_PI);
}

float	fract(float x)
{
	return (x - floor(x));
}

float	sq_dist_pt_segment2s(t_vec2 a, t_vec2 b, t_vec2 c)
{
	t_vec2	ab;
	t_vec2	ac;
	t_vec2	bc;
	float	e;
	float	f;

	ab = sub_vec2s(b, a);
	ac = sub_vec2s(c, a);
	bc = sub_vec2s(c, b);
	e = dot_vec2s(ac, ab);
	if (e <= 0.0f)
		return (dot_vec2s(ac, ac));
	f = dot_vec2s(ab, ab);
	if (e >= f)
		return (dot_vec2s(bc, bc));
	return (dot_vec2s(ac, ac) - e * e / f);
}
