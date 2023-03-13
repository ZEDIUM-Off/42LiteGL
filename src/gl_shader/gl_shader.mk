GL_SHADER_TEX_SRC =	shader_texture/texture2DArray.c \
										shader_texture/texture_rect.c \
										shader_texture/texture_cubemap.c \
										shader_texture/texture1D.c \
										shader_texture/texture2D.c \
										shader_texture/texture3D.c

GL_SHADER_SRC = $(GL_SHADER_TEX_SRC) gl_shader.c

GL_SHADER_PATH = src/gl_shader/