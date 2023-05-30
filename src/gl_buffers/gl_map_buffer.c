/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_map_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:10:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/25 14:21:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	*gl_map_buffer(t_gl_context *c, t_gl_enum target, t_gl_enum access)
{
	void	*data;

	if (target != GL_ARRAY_BUFFER && target != GL_ELEMENT_ARRAY_BUFFER)
		return ((set_err(c, GL_INVALID_ENUM)), NULL);
	if (access != GL_READ_ONLY
		&& access != GL_WRITE_ONLY && access != GL_READ_WRITE)
		return ((set_err(c, GL_INVALID_ENUM)), NULL);
	target -= GL_ARRAY_BUFFER;
	data = NULL;
	lgl_get_buffer_data(c, c->bound_buffers[target], &data);
	return (data);
}
