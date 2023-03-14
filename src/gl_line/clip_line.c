/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:46:16 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 10:47:40 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	clip_line(float denom, float num, float *tmin, float *tmax)
{
	float	t;

	if (denom > 0)
	{
		t = num / denom;
		if (t > *tmax)
			return (0);
		if (t > *tmin)
			*tmin = t;
	}
	else if (denom < 0)
	{
		t = num / denom;
		if (t < *tmin)
			return (0);
		if (t < *tmax)
			*tmax = t;
	}
	else if (num > 0)
		return (0);
	return (1);
}
