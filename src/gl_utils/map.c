/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:06:41 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 22:10:18 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	map(float value, float new_min, float new_max)
{
	return ((value - (-1.0f)) / (1.0f - (-1.0f))
		* (new_max - new_min) + new_min);
}
