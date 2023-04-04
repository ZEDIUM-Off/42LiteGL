CVEC_CLEAR_SRC =	cvec_clear/cvec_gl_buffer_clear.c \
									cvec_clear/cvec_glVertex_Array_clear.c \
									cvec_clear/cvec_glTexture_clear.c \
									cvec_clear/cvec_glProgram_clear.c \
									cvec_clear/cvec_glVertex_clear.c \
									cvec_clear/cvec_float_clear.c \
									cvec_clear/cvec_vec3_clear.c \
									cvec_clear/cvec_vec2_clear.c \
									cvec_clear/cvec_ivec3_clear.c

CVEC_COPY_SRC =		cvec_copy/cvec_gl_buffer_copy.c \
									cvec_copy/cvec_glVertex_Array_copy.c \
									cvec_copy/cvec_glTexture_copy.c \
									cvec_copy/cvec_glProgram_copy.c \
									cvec_copy/cvec_glVertex_copy.c \
									cvec_copy/cvec_float_copy.c \
									cvec_copy/cvec_vec3_copy.c \
									cvec_copy/cvec_vec2_copy.c \
									cvec_copy/cvec_ivec3_copy.c

CVEC_INSERT_SRC =	cvec_insert/cvec_gl_buffer_insert.c \
									cvec_insert/cvec_glVertex_Array_insert.c \
									cvec_insert/cvec_glTexture_insert.c \
									cvec_insert/cvec_glProgram_insert.c \
									cvec_insert/cvec_glVertex_insert.c \
									cvec_insert/cvec_float_insert.c \
									cvec_insert/cvec_vec3_insert.c \
									cvec_insert/cvec_vec2_insert.c \
									cvec_insert/cvec_ivec3_insert.c

CVEC_PUSH_POP_SRC =	cvec_push_pop/cvec_gl_buffer_push_pop.c \
									cvec_push_pop/cvec_glVertex_Array_push_pop.c \
									cvec_push_pop/cvec_glTexture_push_pop.c \
									cvec_push_pop/cvec_glProgram_push_pop.c \
									cvec_push_pop/cvec_glVertex_push_pop.c \
									cvec_push_pop/cvec_float_push_pop.c \
									cvec_push_pop/cvec_vec3_push_pop.c \
									cvec_push_pop/cvec_vec2_push_pop.c \
									cvec_push_pop/cvec_ivec3_push_pop.c

CVEC_SET_SRC =		cvec_set/cvec_gl_buffer_set.c \
									cvec_set/cvec_glVertex_Array_set.c \
									cvec_set/cvec_glTexture_set.c \
									cvec_set/cvec_glProgram_set.c \
									cvec_set/cvec_glVertex_set.c \
									cvec_set/cvec_float_set.c \
									cvec_set/cvec_vec3_set.c \
									cvec_set/cvec_vec2_set.c \
									cvec_set/cvec_ivec3_set.c

CVEC_UTILS_SRC = 	cvec_utils/cvec_gl_buffer_utils.c \
									cvec_utils/cvec_glVertex_Array_utils.c \
									cvec_utils/cvec_glTexture_utils.c \
									cvec_utils/cvec_glProgram_utils.c \
									cvec_utils/cvec_glVertex_utils.c \
									cvec_utils/cvec_float_utils.c \
									cvec_utils/cvec_vec3_utils.c \
									cvec_utils/cvec_vec2_utils.c \
									cvec_utils/cvec_ivec3_utils.c

CVEC_SRC = $(CVEC_CLEAR_SRC) $(CVEC_COPY_SRC) $(CVEC_INSERT_SRC) $(CVEC_PUSH_POP_SRC) $(CVEC_SET_SRC) $(CVEC_UTILS_SRC)
CVEC_SRC += cvec_float.c cvec_gl_buffer.c cvec_glProgram.c cvec_glTexture.c cvec_glVertex.c cvec_glVertex_Array.c cvec_ivec3.c cvec_vec2.c cvec_vec3.c

CVEC_INCLUDE = -Icvec.h
CVEC_PATH = src/cvec/