DRAW_LINE_SRC =	draw_line/draw_line_vars.c \
								draw_line/draw_thick_line_shader.c \
								draw_line/draw_line_shader.c \
								draw_line/draw_line_clip.c \
								draw_line/draw_perp_line.c \
								draw_line/set_vars_coords.c \

DRAW_MODES_SRC =	draw_modes/draw_modes_base.c \
									draw_modes/draw_modes_strip.c

DRAW_POINT_SRC =	draw_point/draw_point.c

DRAW_TRIANGLE_SRC =	draw_triangle/draw_triangle_clip.c \
										draw_triangle/draw_triangle.c \
										draw_triangle/draw_triangle_fill.c \
										draw_triangle/draw_tri_vars.c \
										draw_triangle/draw_triangle_point.c \
										draw_triangle/draw_triangle_line.c \

GL_DRAW_SRC = $(DRAW_LINE_SRC) $(DRAW_MODES_SRC) $(DRAW_POINT_SRC) $(DRAW_TRIANGLE_SRC)
GL_DRAW_SRC += draw_pixel.c \
						gl_draw_arrays.c \
						gl_multi_draw_arrays.c \
						gl_draw_arrays_instanced.c \
						gl_draw_arrays_instanced_base_instance.c \
						gl_draw_elements.c \
						gl_multi_draw_elements.c \
						gl_draw_elements_instanced.c \
						gl_draw_elements_instanced_base_instance.c \
						run_pipeline.c \
						lgl_draw_frame.c

GL_DRAW_PATH = src/gl_draw/
DRAW_INCLUDE = -Igl_draw.h
