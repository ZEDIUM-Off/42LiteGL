/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:50:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 11:59:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <lite_gl.h>

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;

t_vec2	add_vec2s(t_vec2 v1, t_vec2 v2);
t_vec3	add_vec3s(t_vec3 v1, t_vec3 v2);
t_vec4	add_vec4s(t_vec4 v1, t_vec4 v2);

float	angle_between_vec3(t_vec3 v1, t_vec3 v2);

t_vec2	vec4_to_vec2(t_vec4 v);
t_vec3	vec4_to_vec3(t_vec4 v);
t_vec2	vec4_to_vec2h(t_vec4 v);
t_vec3	vec4_to_vec3h(t_vec4 v);

t_vec3	cross_product(t_vec3 v1, t_vec3 v2);

float	distance_vec2(t_vec2 v1, t_vec2 v2);
float	distance_vec3(t_vec3 v1, t_vec3 v2);

t_vec2	div_vec2s(t_vec2 v1, t_vec2 v2);
t_vec3	div_vec3s(t_vec3 v1, t_vec3 v2);
t_vec4	div_vec4s(t_vec4 v1, t_vec4 v2);

float	dot_vec2s(t_vec2 v1, t_vec2 v2);
float	dot_vec3s(t_vec3 v1, t_vec3 v2);
float	dot_vec4s(t_vec4 v1, t_vec4 v2);

int		equal_epsilon_vec2s(t_vec2 v1, t_vec2 v2, float eps);
int		equal_epsilon_vec3s(t_vec3 v1, t_vec3 v2, float eps);
int		equal_epsilon_vec4s(t_vec4 v1, t_vec4 v2, float eps);

int		equal_vec2s(t_vec2 v1, t_vec2 v2);
int		equal_vec3s(t_vec3 v1, t_vec3 v2);
int		equal_vec4s(t_vec4 v1, t_vec4 v2);

float	vec2_lenght(t_vec2 v);
float	vec3_lenght(t_vec3 v);
float	vec4_lenght(t_vec4 v);

t_vec2	make_vec2(float x, float y);
t_vec3	make_vec3(float x, float y, float z);
t_vec4	make_vec4(float x, float y, float z, float w);

t_vec2	mult_vec2s(t_vec2 v1, t_vec2 v2);
t_vec3	mult_vec3s(t_vec3 v1, t_vec3 v2);
t_vec4	mult_vec4s(t_vec4 v1, t_vec4 v2);

t_vec2	negate_vec2(t_vec2 v);
t_vec3	negate_vec3(t_vec3 v);
t_vec4	negate_vec4(t_vec4 v);

t_vec2	norm_vec2(t_vec2 v);
t_vec3	norm_vec3(t_vec3 v);
t_vec4	norm_vec4(t_vec4 v);

void	normalize_vec2(t_vec2 *v);
void	normalize_vec3(t_vec3 *v);
void	normalize_vec4(t_vec4 *v);

t_vec3	reflect_vec3(t_vec3 v, t_vec3 n);

t_vec2	scale_vec2s(t_vec2 v, float s);
t_vec3	scale_vec3s(t_vec3 v, float s);
t_vec4	scale_vec4s(t_vec4 v, float s);

void	set_vec2(t_vec2 *v, float x, float y);
void	set_vec3(t_vec3 *v, float x, float y, float z);
void	set_vec4(t_vec4 *v, float *coords);

t_vec2	sub_vec2s(t_vec2 v1, t_vec2 v2);
t_vec3	sub_vec3s(t_vec3 v1, t_vec3 v2);
t_vec4	sub_vec4s(t_vec4 v1, t_vec4 v2);

#endif