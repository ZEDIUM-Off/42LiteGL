/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:03:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/03 12:04:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	smooth_step(float edge0, float edge1, float x)
{
	float	t;

	t = clamp_01((x - edge0) / (edge1 - edge0));
	return (t * t * (3.0 - 2.0 * t));
}
