MAT2_SRC =	matrix/mat2/mat2_set_vec2.c \
						matrix/mat2/mat2_get_vec2.c

MAT3_SRC =	matrix/mat3/mat3_get_c.c \
						matrix/mat3/mat3_set_xyz.c \
						matrix/mat3/mat3_set_c.c \
						matrix/mat3/mat3_get_xyz.c

MAT4_SRC =	matrix/mat4/mat4_get_xyzw.c \
						matrix/mat4/mat4_set_xyzw_vec3.c \
						matrix/mat4/mat4_set_xyzw_vec4.c \
						matrix/mat4/mat4_set_c_vec3.c \
						matrix/mat4/mat4_get_c.c \
						matrix/mat4/mat4_set_c_vec4.c

MAT_OP_SRC =	matrix/operations/mult_mat_mat.c \
							matrix/operations/mult_mat_vec.c \
							matrix/operations/scale_mat.c

MAT_SRC = $(MAT2_SRC) $(MAT3_SRC) $(MAT4_SRC) $(MAT_OP_SRC)
MAT_SRC +=	matrix/make_persp_mat.c \
						matrix/mat_lookAt.c \
						matrix/operations/mult_mat_mat.c \
						matrix/operations/mult_mat_vec.c \
						matrix/operations/scale_mat.c \
						matrix/make_ortho_mat.c \
						matrix/load_rot_mat.c \
						matrix/translation_mat.c \
						matrix/make_viewport_mat.c

VEC_SRC =	vectors/vec_mult.c \
					vectors/vec_add.c \
					vectors/vec_sub.c \
					vectors/vec_norm.c \
					vectors/vec_negate.c \
					vectors/vec_angle.c \
					vectors/vec_set.c \
					vectors/vec_make.c \
					vectors/vec_div.c \
					vectors/vec_dist.c \
					vectors/vec_dot.c \
					vectors/vec_reflect.c \
					vectors/vec_scale.c \
					vectors/vec_convert.c \
					vectors/vec_lenght.c \
					vectors/vec_equal_eps.c \
					vectors/vec_normalize.c \
					vectors/vec_equal.c \
					vectors/vec_cross.c

MATH_SRC = $(VEC_SRC) $(MAT_SRC)
MATH_SRC +=	op.c \
						clamp.c \
						mix.c \
						smooth_step.c \

MATH_INCLUDE = -Igl_math.h

MATH_PATH = src/gl_math