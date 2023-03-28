/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:59:33 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/22 11:33:46 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_MATH_H
# define GL_MATH_H

# include <lite_gl.h>
# include "vectors/vectors.h"
# include "matrix/matrix.h"

float	clamp(float value, float min, float max);
float	clampf(float f, float min, float max);
int		clampi(int i, int min, int max);
float	clamp_01(float value);
float	clampf_01(float f);
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

void	print_mat4(t_mat4 mat, char *name);
void	print_mat3(t_mat3 mat, char *name);
void	print_mat2(t_mat2 mat, char *name);

#endif