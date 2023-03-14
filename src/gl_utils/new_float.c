/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:31:12 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/14 11:29:36 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

float	*new_float4(float x, float y, float z, float w)
{
	float	*vec;

	vec = (float *)malloc(sizeof(float) * 4);
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
	vec[3] = w;
	return (vec);
}

float	*new_float3(float x, float y, float z)
{
	float	*vec;

	vec = (float *)malloc(sizeof(float) * 3);
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
	return (vec);
}

float	*new_float2(float x, float y)
{
	float	*vec;

	vec = (float *)malloc(sizeof(float) * 2);
	vec[0] = x;
	vec[1] = y;
	return (vec);
}

float	**new_float22(float *x, float *y)
{
	float	**vec;

	vec = (float **)malloc(sizeof(float *) * 2);
	vec[0] = x;
	vec[1] = y;
	return (vec);
}
