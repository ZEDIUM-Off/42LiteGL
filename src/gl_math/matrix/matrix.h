/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:16:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/07 11:50:53 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <lite_gl.h>

typedef float	t_mat2[2][2];
typedef float	t_mat3[3][3];
typedef float	t_mat4[4][4];

t_mat2	identity_mat2(void)
{
	return ((t_mat2){
		{1.0f, 0.0f},
		{0.0f, 1.0f}});
}

t_mat3	identity_mat3(void)
{
	return ((t_mat3){
		{1.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f}});
}

t_mat4	identity_mat4(void)
{
	return ((t_mat4){
		{1.0f, 0.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f, 0.0f},
		{0.0f, 0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}});
}

// mat 2
void	set_identity_mat2(t_mat2 mat);
t_vec2	x_mat2(t_mat2 m);
t_vec2	y_mat2(t_mat2 m);
t_vec2	c1_mat2(mat2 m);
t_vec2	c2_mat2(mat2 m);

void	setc1_mat2(t_mat2 m, vec2 v);
void	setc2_mat2(mat2 m, vec2 v);

void	setx_mat2(t_mat2 m, vec2 v);
void	sety_mat2(t_mat2 m, vec2 v);

t_vec2	mult_mat2_vec2(t_mat2 m, t_vec2 v);

// mat 3
void	set_identity_mat3(t_mat3 mat);
t_vec3	x_mat3(t_mat3 m);
t_vec3	y_mat3(t_mat3 m);
t_vec3	z_mat3(t_mat3 m);
t_vec3	c1_mat3(t_mat3 m);
t_vec3	c2_mat3(t_mat3 m);
t_vec3	c3_mat3(t_mat3 m);

void	setc1_mat3(t_mat3 m, t_vec3 v);
void	setc2_mat3(t_mat3 m, t_vec3 v);
void	setc3_mat3(t_mat3 m, t_vec3 v);

void	setx_mat3(t_mat3 m, t_vec3 v);
void	sety_mat3(mat3 m, t_vec3 v);
void	setz_mat3(t_mat3 m, t_vec3 v);

t_vec3	mult_mat3_vec3(t_mat3 m, t_vec3 v);

// mat 4
void	set_identity_mat4(t_mat4 mat);
t_vec4	c1_mat4(t_mat4 m);
t_vec4	c2_mat4(t_mat4 m);
t_vec4	c3_mat4(t_mat4 m);
t_vec4	c4_mat4(t_mat4 m);

t_vec4	x_mat4(t_mat4 m);
t_vec4	y_mat4(t_mat4 m);
t_vec4	z_mat4(t_mat4 m);
t_vec4	w_mat4(t_mat4 m);

//sets 4th row to 0 0 0 1
void	setc1_mat4v3(t_mat4 m, t_vec3 v);
void	setc2_mat4v3(t_mat4 m, t_vec3 v);
void	setc3_mat4v3(t_mat4 m, t_vec3 v);
void	setc4_mat4v3(t_mat4 m, t_vec3 v);

void	setc1_mat4v4(t_mat4 m, t_vec4 v);
void	setc2_mat4v4(t_mat4 m, t_vec4 v);
void	setc3_mat4v4(t_mat4 m, t_vec4 v);
void	setc4_mat4v4(t_mat4 m, t_vec4 v);

//sets 4th column to 0 0 0 1
void	setx_mat4v3(t_mat4 m, t_vec3 v);
void	sety_mat4v3(t_mat4 m, t_vec3 v);
void	setz_mat4v3(t_mat4 m, t_vec3 v);
void	setw_mat4v3(t_mat4 m, t_vec3 v);

void	setx_mat4v4(t_mat4 m, t_vec4 v);
void	sety_mat4v4(t_mat4 m, t_vec4 v);
void	setz_mat4v4(t_mat4 m, t_vec4 v);
void	setw_mat4v4(t_mat4 m, t_vec4 v);

t_vec4	mult_mat4_vec4(t_mat4 m, t_vec4 v);
t_vec3	mult_mat3_vec3(t_mat3 m, t_vec3 v);
t_vec2	mult_mat2_vec2(t_mat2 m, t_vec2 v);
void	mult_mat2_mat2(t_mat2 c, t_mat2 a, t_mat2 b);
void	mult_mat3_mat3(t_mat3 c, t_mat3 a, t_mat3 b);
void	mult_mat4_mat4(t_mat4 c, t_mat4 a, t_mat4 b);
void	scale_mat3(t_mat3 m, float x, float y, float z);
void	scale_mat4(t_mat4 m, float x, float y, float z);

void	load_rotation_mat2(t_mat2 mat, float angle);
void	load_rotation_mat3(t_mat3 mat, t_vec3 v, float angle);
void	load_rotation_mat4(t_mat4 mat, t_vec3 v, float angle);

void	make_orthographic_matrix(
			t_mat4 mat, float	*lr, float *bt, float *near_far);
void	make_perspective_matrix(
			t_mat4 mat, float fov, float aspect, float *near_far);
void	make_perspective_proj_matrix(
			t_mat4 mat, float *lr, float *bt, float *near_far);
void	make_pers_matrix(t_mat4 mat, float z_near, float z_far);
void	make_viewport_matrix(
			t_mat4 mat, float	*xy, unsigned int *wh, int opengl);
void	look_at(t_mat4 mat, t_vec3 eye, t_vec3 center, t_vec3 up);
void	translation_mat4(t_mat4 m, float x, float y, float z);

#endif