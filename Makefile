include src/gl_buffers/gl_buffer.mk
include src/gl_color/gl_color.mk
include src/gl_context/gl_context.mk
include src/gl_draw/gl_draw.mk
include src/gl_getters/gl_getters.mk
include src/gl_line/gl_line.mk
include src/gl_math/gl_math.mk
include src/gl_shader/gl_shader.mk
include src/gl_texture/gl_texture.mk
include src/gl_vertex_arrays/gl_vertex_arrays.mk
include src/gl_vertex_attrib/gl_vertex_attrib.mk

LIBFT_DIR = libft
LIBFT = $(LIB_DIR)/libft.a

SRC	=	$(GL_BUFFER_SRC:%.c=$(GL_BUFFER_PATH)%.c) \
			$(GL_COLOR_SRC:%.c=$(GL_COLOR_PATH)%.c) \
			$(GL_CONTEXT_SRC:%.c=$(GL_CONTEXT_PATH)%.c) \
			$(GL_DRAW_SRC:%.c=$(GL_DRAW_PATH)%.c) \
			$(GL_GETTERS_SRC:%.c=$(GL_GETTERS_PATH)%.c) \
			$(GL_LINE_SRC:%.c=$(GL_LINE_PATH)%.c) \
			$(GL_MATH_SRC:%.c=$(GL_MATH_PATH)%.c) \
			$(GL_SHADER_SRC:%.c=$(GL_SHADER_PATH)%.c) \
			$(GL_TEXTURE_SRC:%.c=$(GL_TEXTURE_PATH)%.c) \
			$(GL_VERTEX_ARRAYS_SRC:%.c=$(GL_VERTEX_ARRAYS_PATH)%.c) \
			$(GL_VERTEX_ATTRIB_SRC:%.c=$(GL_VERTEX_ATTRIB_PATH)%.c)

OBJ = $(SRC:.c=.o)
CFLAGS = -I./src/ -I$(LIBFT_DIR) -Wall -Wextra -Werror
NAME = lite_gl.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	echo $(SRC)
	echo $(OBJ)
	ar rcs $@ $^
	@echo "Libft compiled"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft : 
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT): libft

clean:
	@rm -f $(OBJ)
	@echo "Libft cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "Libft fcleaned"

re: fclean all

.PHONY: all clean fclean re