/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:59:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 12:01:48 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_MATH_H
# define GL_MATH_H

# include <lite_gl.h>
# include "vectors/vectors.h"
# include "matrix/matrix.h"

float	clamp(float value, float min, float max);
float	clamp_01(float value);
t_vec2	clamp_vec2(t_vec2 v, float min, float max);
t_vec3	clamp_vec3(t_vec3 v, float min, float max);
t_vec4	clamp_vec4(t_vec4 v, float min, float max);

float	mix(float x, float y, float a);
t_vec2	mix_vec2(t_vec2 x, t_vec2 y, float a);
t_vec3	mix_vec3(t_vec3 x, t_vec3 y, float a);
t_vec4	mix_vec4(t_vec4 x, t_vec4 y, float a);

float	radians(float degrees);
float	degrees(float radians);
float	fract(float x);
float	sq_dist_pt_segment2s(t_vec2 a, t_vec2 b, t_vec2 c);

float	smooth_step(float edge0, float edge1, float x);

#endif