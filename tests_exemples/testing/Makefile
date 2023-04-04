SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)
NAME = ./test.out
GLFW = /usr/local/Cellar/glfw/3.3.8/lib/
MLX_DIR = ../../mlx-linux/
CFLAGS = -Wall -Wextra -fsanitize=address -g3 -I. -I../../ -I$(MLX_DIR) -lm -I/usr/X11/include #-L$(GLFW) -lglfw
LITE_GL = ../../lite_gl.a
MLX = $(MLX_DIR)libmlx.a

all: $(NAME)

$(NAME): $(OBJS) tests.h
	$(CC) $(CFLAGS) $(OBJS) $(LITE_GL) $(MLX) /usr/X11/lib/libX11.dylib /usr/local/Cellar/libxext/1.3.5/lib/libXext.dylib -o $(NAME)

%.o: %.c $(MLX)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all