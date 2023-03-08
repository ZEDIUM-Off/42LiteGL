/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:17:54 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 10:18:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <lite_gl.h>

t_color	make_color(float r, float g, float b, float a);

t_color	vec4_to_color(t_vec4 v);

t_vec4	color_to_vec4(t_color c);

#endif