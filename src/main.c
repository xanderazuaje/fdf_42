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
#include "stdio.h"

// t_node **

int	main(void)
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_matrix *matrix;
	int	raw_matrix[][4][2] = {
		{{1, 0xff0000},{1, 0xFFAABB}, {1, 0xff0000}, {1, 0xff0000}},
		{{1, 0xff0000},{1, 0xFFAABB}, {1, 0xff0000}, {1, 0xff0000}},
		{{1, 0xff0000},{1, 0xFFAABB}, {1, 0xff0000}, {1, 0xff0000}},
		{{1, 0xff0000},{1, 0xFFAABB}, {1, 0xff0000}, {1, 0xff0000}},
	};
	init_minilib(&mlx, &img, &win);
	matrix = create_matrix(4, 4, raw_matrix);
	matrix->scalar = 20;
	calculate_position(matrix, &img);
	draw_matrix(matrix, &img);
	set_minilib(&mlx, &win, &img);
	return (0);
}
