/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:33:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 15:34:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	*new_int2(int x, int y)
{
	int	*new;

	new = (int *)malloc(sizeof(int) * 2);
	new[0] = x;
	new[1] = y;
	return (new);
}

int	*new_int3(int x, int y, int z)
{
	int	*new;

	new = (int *)malloc(sizeof(int) * 3);
	new[0] = x;
	new[1] = y;
	new[2] = z;
	return (new);
}

int	*new_int4(int x, int y, int z, int w)
{
	int	*new;

	new = (int *)malloc(sizeof(int) * 4);
	new[0] = x;
	new[1] = y;
	new[2] = z;
	new[3] = w;
	return (new);
}
