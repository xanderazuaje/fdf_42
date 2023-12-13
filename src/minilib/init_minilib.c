/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:53:17 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/29 13:08:06by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"


int	init_minilib(void **mlx, t_img *img, void **win)
{
	*mlx = mlx_init();
	*win = mlx_new_window(*mlx, IMG_W, IMG_H, "FdF by Sausage");
	img->img_buff = mlx_new_image(*mlx, IMG_W, IMG_H);
	img->img_addr = mlx_get_data_addr(img->img_buff, &img->bits_per_pixel, &img->size_line,
		&img->endian);
	img->w = IMG_W;
	img->h = IMG_H;
	img->is_click_pressed = 0;
	mlx_hook(*win, 17, (1L << 17), &exittt, img);
	return (0);
}
