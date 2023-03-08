/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:04:30 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/08 11:56:03 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

int	init_gl_context(t_GLContext *c, t_context_settings setts)
{
	if (!init_img_context(c, &setts))
		return (0);
	set_context_vars(c, &setts);
	return (1);
}
