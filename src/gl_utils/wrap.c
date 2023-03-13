/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:08:25 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 21:25:19 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	wrap(int i, int size, t_gl_enum mode)
{
	int	tmp;

	if (mode == GL_REPEAT)
	{
		tmp = i - size * (i / size);
		if (tmp < 0)
			tmp = size + tmp;
		return (tmp);
	}
	else if (mode == GL_CLAMP_TO_EDGE)
		return (clampi(i, 0, size - 1));
	else if (mode == GL_MIRRORED_REPEAT)
	{
		if (i < 0)
			i = -i;
		tmp = i / size;
		if (tmp % 2)
			return ((size - 1) - (i - tmp * size));
		else
			return (i - tmp * size);
		return (tmp);
	}
	else
		return (ft_assert(0), 0);
}
