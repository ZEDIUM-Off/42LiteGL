SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)
NAME = ./test.out
GLFW = /usr/local/Cellar/glfw/3.3.8/lib/
CFLAGS = -Wall -Wextra -fsanitize=address -g3 -I. -I../../ -I../../MLX42/include/MLX42/ -L$(GLFW) -lglfw
LITE_GL = ../../lite_gl.a
MLX = ../../MLX42/build/libmlx42.a

all: $(NAME)

$(NAME): $(OBJS) tests.h
	$(CC) $(CFLAGS) $(OBJS) $(LITE_GL) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all