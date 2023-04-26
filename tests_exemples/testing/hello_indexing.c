/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_indexing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:20:22 by  mchenava         #+#    #+#             */
/*   Updated: 2023/04/14 15:36:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

void	set_buffers(t_gl_context *c)
{
	float points[] =
	{
		-0.25, 0.00, -0.25, -0.20, 0.00, -0.25, -0.15, 0.12, -0.25, -0.10, 0.25, -0.25, -0.05, 0.38, -0.25, 0.00, 0.50, -0.25, 0.05, 0.62, -0.25, 0.10, 0.75, -0.25, 0.15, 0.88, -0.25, 0.20, 1.00, -0.25, 0.25, 1.12, -0.25, 
 -0.25, 0.00, -0.19, -0.20, 0.00, -0.19, -0.15, 0.00, -0.19, -0.10, 0.12, -0.19, -0.05, 0.25, -0.19, 0.00, 0.38, -0.19, 0.05, 0.50, -0.19, 0.10, 0.62, -0.19, 0.15, 0.75, -0.19, 0.20, 0.88, -0.19, 0.25, 1.00, -0.19, 
 -0.25, 0.00, -0.12, -0.20, 0.00, -0.12, -0.15, 0.00, -0.12, -0.10, 0.00, -0.12, -0.05, 0.12, -0.12, 0.00, 0.25, -0.12, 0.05, 0.38, -0.12, 0.10, 0.50, -0.12, 0.15, 0.62, -0.12, 0.20, 0.75, -0.12, 0.25, 0.88, -0.12, 
 -0.25, 0.00, -0.06, -0.20, 0.00, -0.06, -0.15, 0.00, -0.06, -0.10, 0.00, -0.06, -0.05, 0.00, -0.06, 0.00, 0.12, -0.06, 0.05, 0.25, -0.06, 0.10, 0.38, -0.06, 0.15, 0.50, -0.06, 0.20, 0.62, -0.06, 0.25, 0.75, -0.06, 
 -0.25, 0.00, 0.00, -0.20, 0.00, 0.00, -0.15, 0.00, 0.00, -0.10, 0.00, 0.00, -0.05, 0.00, 0.00, 0.00, 0.00, 0.00, 0.05, 0.12, 0.00, 0.10, 0.25, 0.00, 0.15, 0.38, 0.00, 0.20, 0.50, 0.00, 0.25, 0.62, 0.00, 
 -0.25, 0.00, 0.06, -0.20, 0.00, 0.06, -0.15, 0.00, 0.06, -0.10, 0.00, 0.06, -0.05, 0.00, 0.06, 0.00, 0.00, 0.06, 0.05, 0.00, 0.06, 0.10, 0.12, 0.06, 0.15, 0.25, 0.06, 0.20, 0.38, 0.06, 0.25, 0.50, 0.06, 
 -0.25, 0.00, 0.12, -0.20, 0.00, 0.12, -0.15, 0.00, 0.12, -0.10, 0.00, 0.12, -0.05, 0.00, 0.12, 0.00, 0.00, 0.12, 0.05, 0.00, 0.12, 0.10, 0.00, 0.12, 0.15, 0.12, 0.12, 0.20, 0.25, 0.12, 0.25, 0.38, 0.12, 
 -0.25, 0.00, 0.19, -0.20, 0.00, 0.19, -0.15, 0.00, 0.19, -0.10, 0.00, 0.19, -0.05, 0.00, 0.19, 0.00, 0.00, 0.19, 0.05, 0.00, 0.19, 0.10, 0.00, 0.19, 0.15, 0.00, 0.19, 0.20, 0.12, 0.19, 0.25, 0.25, 0.19,
	};

	
	// not that it matters here, but using CCW
	unsigned int indices[] = {
		0, 11, 1, 11, 1, 12, 
1, 12, 2, 12, 2, 13, 
2, 13, 3, 13, 3, 14, 
3, 14, 4, 14, 4, 15, 
4, 15, 5, 15, 5, 16, 
5, 16, 6, 16, 6, 17, 
6, 17, 7, 17, 7, 18, 
7, 18, 8, 18, 8, 19, 
8, 19, 9, 19, 9, 20, 
9, 20, 10, 20, 10, 21, 
11, 22, 12, 22, 12, 23, 
12, 23, 13, 23, 13, 24, 
13, 24, 14, 24, 14, 25, 
14, 25, 15, 25, 15, 26, 
15, 26, 16, 26, 16, 27, 
16, 27, 17, 27, 17, 28, 
17, 28, 18, 28, 18, 29, 
18, 29, 19, 29, 19, 30, 
19, 30, 20, 30, 20, 31, 
20, 31, 21, 31, 21, 32, 
22, 33, 23, 33, 23, 34, 
23, 34, 24, 34, 24, 35, 
24, 35, 25, 35, 25, 36, 
25, 36, 26, 36, 26, 37, 
26, 37, 27, 37, 27, 38, 
27, 38, 28, 38, 28, 39, 
28, 39, 29, 39, 29, 40, 
29, 40, 30, 40, 30, 41, 
30, 41, 31, 41, 31, 42, 
31, 42, 32, 42, 32, 43, 
33, 44, 34, 44, 34, 45, 
34, 45, 35, 45, 35, 46, 
35, 46, 36, 46, 36, 47, 
36, 47, 37, 47, 37, 48, 
37, 48, 38, 48, 38, 49, 
38, 49, 39, 49, 39, 50, 
39, 50, 40, 50, 40, 51, 
40, 51, 41, 51, 41, 52, 
41, 52, 42, 52, 42, 53, 
42, 53, 43, 53, 43, 54, 
44, 55, 45, 55, 45, 56, 
45, 56, 46, 56, 46, 57, 
46, 57, 47, 57, 47, 58, 
47, 58, 48, 58, 48, 59, 
48, 59, 49, 59, 49, 60, 
49, 60, 50, 60, 50, 61, 
50, 61, 51, 61, 51, 62, 
51, 62, 52, 62, 52, 63, 
52, 63, 53, 63, 53, 64, 
53, 64, 54, 64, 54, 65, 
55, 66, 56, 66, 56, 67, 
56, 67, 57, 67, 57, 68, 
57, 68, 58, 68, 58, 69, 
58, 69, 59, 69, 59, 70, 
59, 70, 60, 70, 60, 71, 
60, 71, 61, 71, 61, 72, 
61, 72, 62, 72, 62, 73, 
62, 73, 63, 73, 63, 74, 
63, 74, 64, 74, 64, 75, 
64, 75, 65, 75, 65, 76, 
66, 77, 67, 77, 67, 78, 
67, 78, 68, 78, 68, 79, 
68, 79, 69, 79, 69, 80, 
69, 80, 70, 80, 70, 81, 
70, 81, 71, 81, 71, 82, 
71, 82, 72, 82, 72, 83, 
72, 83, 73, 83, 73, 84, 
73, 84, 74, 84, 74, 85, 
74, 85, 75, 85, 75, 86, 
75, 86, 76, 86, 76, 87, 
77, 88, 78, 88, 78, 89, 
78, 89, 79, 89, 79, 90, 
79, 90, 80, 90, 80, 91, 
80, 91, 81, 91, 81, 92, 
81, 92, 82, 92, 82, 93, 
82, 93, 83, 93, 83, 94, 
83, 94, 84, 94, 84, 95, 
84, 95, 85, 95, 85, 96, 
85, 96, 86, 96, 86, 97, 
86, 97, 87, 97, 87, 98,
		};
	
	t_gl_uint			square;
	t_gl_uint			elements;
	t_gl_vertex_attrib	attr;

	gl_gen_buffers(c, 1, &square);
	gl_bind_buffer(c, GL_ARRAY_BUFFER, square);
	gl_buffer_data(c, GL_ARRAY_BUFFER, sizeof(points), points);
	gl_gen_buffers(c, 1, &elements);
	gl_bind_buffer(c, GL_ELEMENT_ARRAY_BUFFER, elements);
	gl_buffer_data(c, GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices);
	gl_enable_vertex_attrib_array(c, 0);
	attr = (t_gl_vertex_attrib){.size = 3, .type = GL_FLOAT,
		.normalized = GL_FALSE, .stride = 0};
	gl_vertex_attrib_pointer(c, 0, attr, 0);
}

void	hello_indexing(t_gl_context *c, int argc, char **argv, void *data)
{
	t_draw_elements_settings	sett;

	set_buffers(c);
	gl_clear_color(c, new_float4(0.0f, 0.0f, 0.0f, 1.0f));
	gl_clear(c, GL_COLOR_BUFFER_BIT);
	gl_polygon_mode(c, GL_FRONT_AND_BACK, GL_LINE);
	sett = (t_draw_elements_settings){10 * 8 * 6, GL_UNSIGNED_INT, 0};
	gl_draw_elements(c, GL_TRIANGLES, &sett);
}
