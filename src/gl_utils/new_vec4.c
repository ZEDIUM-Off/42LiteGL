/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:57:34 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 21:34:12 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_vec4	*new_vec42(t_vec4 v1, t_vec4 v2)
{
	t_vec4	*new;

	new = (t_vec4 *)malloc(sizeof(t_vec4) * 2);
	new[0] = v1;
	new[1] = v2;
	return (new);
}

t_vec4	*new_vec43(t_vec4 v1, t_vec4 v2, t_vec4 v3)
{
	t_vec4	*new;

	new = (t_vec4 *)malloc(sizeof(t_vec4) * 3);
	new[0] = v1;
	new[1] = v2;
	new[2] = v3;
	return (new);
}

t_vec4	*new_vec44(t_vec4 v1, t_vec4 v2, t_vec4 v3, t_vec4 v4)
{
	t_vec4	*new;

	new = (t_vec4 *)malloc(sizeof(t_vec4) * 4);
	new[0] = v1;
	new[1] = v2;
	new[2] = v3;
	new[3] = v4;
	return (new);
}
