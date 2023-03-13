/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:33:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 15:39:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

unsigned int	*new_uint2(int x, int y)
{
	unsigned int	*new;

	new = (unsigned int *)malloc(sizeof(unsigned int) * 2);
	new[0] = x;
	new[1] = y;
	return (new);
}

unsigned int	*new_uint3(int x, int y, int z)
{
	unsigned int	*new;

	new = (unsigned int *)malloc(sizeof(unsigned int) * 3);
	new[0] = x;
	new[1] = y;
	new[2] = z;
	return (new);
}

unsigned int	*new_uint4(int x, int y, int z, int w)
{
	unsigned int	*new;

	new = (unsigned int *)malloc(sizeof(unsigned int) * 4);
	new[0] = x;
	new[1] = y;
	new[2] = z;
	new[3] = w;
	return (new);
}
