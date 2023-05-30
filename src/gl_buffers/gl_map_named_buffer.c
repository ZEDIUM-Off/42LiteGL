/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_map_named_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:25:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/25 14:21:50 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	*gl_map_named_buffer(
	t_gl_context *c, t_gl_uint buffer, t_gl_enum access)
{
	void	*data;

	if (access != GL_READ_ONLY && access != GL_WRITE_ONLY
		&& access != GL_READ_WRITE)
		return ((set_err(c, GL_INVALID_ENUM)), NULL);
	data = NULL;
	lgl_get_buffer_data(c, buffer, &data);
	return (data);
}
