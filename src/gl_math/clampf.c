/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clampf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:09:14 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/08 11:12:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	clampf(float f, float min, float max)
{
	if (f < min)
		return (min);
	if (f > max)
		return (max);
	return (f);
}

float	clampf_01(float f)
{
	return (clampf(f, 0.0f, 1.0f));
}

int	clampi(int i, int min, int max)
{
	if (i < min)
		return (min);
	if (i > max)
		return (max);
	return (i);
}
