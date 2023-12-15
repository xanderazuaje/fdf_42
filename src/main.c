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
	t_vars	vars;

	
	int	raw_matrix[][6][2] = {
		{{13, 0xff0000}, {0, 0xFFAABB}, {0, 0xff0000}, {0, 0xff0000}, {0, 0xff0000}, {3, 0xff0000}},
		{{0, 0xff0000}, {2, 0xFFAABB}, {0, 0xff0000}, {0, 0xff0000}, {0, 0xff0000}, {3, 0xff0000}},
		{{1, 0xff0000}, {2, 0xFFAABB}, {0, 0xff0000}, {0, 0xff0000}, {0, 0xff0000}, {3, 0xff0000}},
		{{0, 0xff0000}, {0, 0xFFAABB}, {0, 0xff0000}, {0, 0xff0000}, {0, 0xff0000}, {3, 0xff0000}},
		{{0, 0xff0000}, {0, 0xFFAABB}, {0, 0xff0000}, {0, 0xff0000}, {0, 0xff0000}, {3, 0xff0000}},
		{{0, 0xff0000}, {0, 0xFFAABB}, {0, 0xff0000}, {0, 0xff0000}, {0, 0xff0000}, {3, 0xff0000}},
	};
	init_minilib(&mlx, &img, &win);
	matrix = create_matrix(6, 6, raw_matrix);
	matrix->scalar = 20;
	vars.img = &img;
	vars.matrix = matrix;
	vars.mlx = &mlx;
	vars.win = &win;
	calculate_position(matrix, &img);
	draw_matrix(&vars);
	set_minilib(&vars);
	return (0);
}
