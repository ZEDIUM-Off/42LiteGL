/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gl_sizei.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:34:48 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 15:36:59 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_sizei	*new_sizei2(int x, int y)
{
	t_gl_sizei	*new;

	new = (t_gl_sizei *)malloc(sizeof(t_gl_sizei) * 2);
	new[0] = x;
	new[1] = y;
	return (new);
}

t_gl_sizei	*new_sizei3(int x, int y, int z)
{
	t_gl_sizei	*new;

	new = (t_gl_sizei *)malloc(sizeof(t_gl_sizei) * 3);
	new[0] = x;
	new[1] = y;
	new[2] = z;
	return (new);
}

t_gl_sizei	*new_sizei4(int x, int y, int z, int w)
{
	t_gl_sizei	*new;

	new = (t_gl_sizei *)malloc(sizeof(t_gl_sizei) * 4);
	new[0] = x;
	new[1] = y;
	new[2] = z;
	new[3] = w;
	return (new);
}
