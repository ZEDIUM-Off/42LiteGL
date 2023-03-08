DRAW_LINE_SRC =	draw_line/draw_line_vars.c \
								draw_line/draw_thick_line_shader.c \
								draw_line/draw_line_shader.c \
								draw_line/draw_line_clip.c \
								draw_line/draw_perp_line.c

DRAW_MODES_SRC =	draw_modes/draw_modes_base.c \
									draw_modes/draw_modes_strip.c

DRAW_POINT_SRC =	draw_point/draw_point.c

DRAW_TRIANGLE_SRC =	draw_triangle/draw_triangle_clip.c \
										draw_triangle/draw_triangle.c \
										draw_triangle/draw_triangle_fill.c \
										raw_triangle/draw_tri_vars.c

DRAW_SRC = $(DRAW_LINE_SRC) $(DRAW_MODES_SRC) $(DRAW_POINT_SRC) $(DRAW_TRIANGLE_SRC)
DRAW_SRC += draw_pixel.c gl_draw.c mlx_draw.c

DRAW_INCLUDE = -Igl_draw.h