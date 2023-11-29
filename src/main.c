/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:38:26 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/28 16:40:29by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_node **

int	main(void)
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_node	*node1;
	t_node	*node2;

	node1 = create_node(5, 5, 10, "0xFFFFFFFF");
	node2 = create_node(10, 10, 10, "0xFFFFFFFF");
	init_minilib(&mlx, &img, &win);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			put_pixel(&img, i, j, 0xffffff);
		}
	mlx_put_image_to_window(mlx, win, img.img_buff, 0, 0);
	mlx_hook(win, 2, 1L << 0, key_action, img.img_buff);
	mlx_loop(mlx);
	return (0);
}
