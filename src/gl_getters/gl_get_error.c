/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_get_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:19:31 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/09 11:23:45 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

t_gl_enum	gl_get_error(t_GLContext *c)
{
	t_gl_enum	error;

	error = c->error;
	c->error = GL_NO_ERROR;
	return (error);
}
