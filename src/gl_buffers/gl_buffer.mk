GL_BUFFER_SRC =	gl_gen_buffers.c \
								gl_delete_buffers.c \
								gl_bind_buffer.c \
								gl_map_buffer.c \
								gl_named_buffer_sub_data.c \
								gl_buffer_sub_data.c \
								gl_buffer_data.c \
								gl_map_named_buffer.c \
								gl_named_buffer_data.c

GL_BUFFER_PATH = src/gl_buffers/
GL_BUFFER_INCLUDE = -Igl_buffer.h