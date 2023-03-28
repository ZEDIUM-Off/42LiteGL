/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ivec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:53:39 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/28 10:54:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_ivec3	make_ivec3(int x, int y, int z)
{
	t_ivec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
