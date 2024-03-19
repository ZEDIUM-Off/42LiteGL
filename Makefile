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
include src/gl_utils/gl_utils.mk
include src/cvec/cvec.mk

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX = MLX42/build/libmlx42.a
MLXH = MLX42/include/MLX42
GLFW = /usr/local/Cellar/glfw/3.3.8/lib/
EXEMPLE_MLX = tests_exemples/exemples/using_mlx42/rotating_cube_mlx.c

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
			$(GL_VERTEX_ATTRIB_SRC:%.c=$(GL_VERTEX_ATTRIB_PATH)%.c) \
			$(GL_UTILS_SRC:%.c=$(GL_UTILS_PATH)%.c) \
			$(CVEC_SRC:%.c=$(CVEC_PATH)%.c) \

SRC += $(LIBFT_DIR)/ft_realloc.c $(LIBFT_DIR)/ft_assert.c $(LIBFT_DIR)/ft_memcpy.c $(LIBFT_DIR)/ft_memmove.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR) -g3 #-fsanitize=address  #-lm
NAME = lite_gl.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
	@echo "Lite_gl compiled"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): lib

demo_mlx : $(NAME)
	$(CC) -fsanitize=address -g3 -I. -I$(MLXH) -I$(LIBFT_DIR) -L$(GLFW) -lglfw $(EXEMPLE_MLX) $(MLX) $(NAME) -o $(EXEMPLE_MLX:.c=.out)

exec_demo_mlx : demo_mlx
	./$(EXEMPLE_MLX:.c=.out)

run_tests : $(NAME)
	$(MAKE) -C tests_exemples/testing/ re
	./tests_exemples/testing/test.out $(TEST_ARGS)

lib :
	$(MAKE) -C $(LIBFT_DIR)
	@echo "Libft compiled"

clean:
	@rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(EXEMPLE_MLX:.c=.out)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
