/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:03:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/24 12:03:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec3	*new_vec32(t_vec3 v1, t_vec3 v2)
{
	t_vec3	*new;

	new = (t_vec3 *)malloc(sizeof(t_vec3) * 2);
	new[0] = v1;
	new[1] = v2;
	return (new);
}

t_vec3	*new_vec33(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_vec3	*new;

	new = (t_vec3 *)malloc(sizeof(t_vec3) * 3);
	new[0] = v1;
	new[1] = v2;
	new[2] = v3;
	return (new);
}

t_vec3	*new_vec34(t_vec3 v1, t_vec3 v2, t_vec3 v3, t_vec3 v4)
{
	t_vec3	*new;

	new = (t_vec3 *)malloc(sizeof(t_vec3) * 4);
	new[0] = v1;
	new[1] = v2;
	new[2] = v3;
	new[3] = v4;
	return (new);
}
