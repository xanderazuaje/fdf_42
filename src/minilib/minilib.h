/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:58:32 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/13 01:15:57 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H
# define MINILIB_H
# include "../fdf.h"

typedef struct s_node	t_node;
typedef struct s_matrix t_matrix;

enum e_keys
{
	ESC = 53,
	NUMPAD_0 = 82,
	NUMPAD_1 = 83,
	NUMPAD_2 = 84,
	NUMPAD_3 = 85,
	NUMPAD_4 = 86,
	NUMPAD_5 = 87,
	NUMPAD_6 = 88,
	NUMPAD_7 = 89,
	NUMPAD_8 = 91,
	NUMPAD_9 = 92,
};

typedef enum e_mouse_events
{
	LEFT_CLICK = 1,
	RIGHT_CLICK,
	MIDDLE_CLICK,
	SCROLL_UP,
	SCROLL_DOWN
} t_mouse_events;

typedef enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}						t_events;

typedef enum e_masks
{
	MASK_NO_MASK = 0L,
	MASK_KEYPRESS = (1L << 0),
	MASK_KEYRELEASE = (1L << 1),
}						t_masks;

typedef enum e_projection
{
	ISOMETRIC,
	CAVALIER,
	SPHERE,
	CONE
} t_projection;

typedef struct s_control_panel
{
	t_projection		projection;
	int					current_coords[2];
	
}						t_control_panel;
typedef struct s_img
{
	int					w;
	int					h;
	void				*img_buff;
	void				*img_addr;
	int					is_click_pressed;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_control_panel		cp;
}						t_img;

typedef struct s_vars
{
	t_img				*img;
	t_matrix			*matrix;
	void				**mlx;
	void				**win;
} t_vars;

typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

int						exittt(void);
int						key_action(int key, t_img *img);
int						init_minilib(void **mlx, t_img *img, void **win);
void					put_pixel(t_img *img, int x, int y, int color);
void					draw_line(t_node *node1, t_node *node2, t_img *img);
void					set_minilib(t_vars *vars);
int						get_interpolation(int c_dest, int c_origin, int steps);
int						mouse_press(int button, int x, int y, t_vars *vars);
int						mouse_move(int x, int y, t_vars *vars);
int 					mouse_leave(int button, int x, int y, t_vars *vars);
void					paint_it_black(t_img *img, int w, int h);
#endif