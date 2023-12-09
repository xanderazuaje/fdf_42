/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:58:32 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/06 21:22:56 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H 
# define MINILIB_H
# include "../fdf.h"

typedef struct s_node t_node;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
enum
{
	MASK_NO_MASK = 0L,
	MASK_KEYPRESS = (1L << 0),
	MASK_KEYRELEASE = (1L << 1),
};
typedef struct s_img
{
	int		w;
	int		h;
	void	*img_buff;
	void	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_rgb
{
	int r;
	int g;
	int b;
} t_rgb;

int			exittt(void);
int			key_action(int key, t_img *img);
int			init_minilib(void **mlx, t_img *img, void **win);
void		put_pixel(t_img *img, int x, int y, int color);
void		draw_line(t_node *node1, t_node *node2, t_img *img);
void		set_minilib(void **mlx, void **win, t_img *img);
int			get_interpolation(int c_dest, int c_origin, int steps);
#endif