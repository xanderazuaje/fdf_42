/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:39:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:22:53 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void	draw_matrix(t_vars *vars)
{
	t_node	*c_node;
	size_t	i;
	void	*prev;

	prev = ((i = 0), vars->img.img_buff);
	vars->img.img_buff = mlx_new_image(vars->mlx, IMG_W, IMG_H);
	free(prev);
	if (!vars->img.img_buff)
		return ;
	prev = vars->img.img_addr;
	vars->img.img_addr = mlx_get_data_addr(vars->img.img_buff,
			&vars->img.bits_per_pixel, &vars->img.size_line, &vars->img.endian);
	free(prev);
	if (!vars->img.img_addr)
		return ;
	while (i < (vars->matrix->columns * vars->matrix->rows))
	{
		c_node = &((vars->matrix->elements)[i]);
		if (c_node->h_next)
			draw_line(c_node, c_node->h_next, &vars->img);
		if (c_node->v_next)
			draw_line(c_node, c_node->v_next, &vars->img);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_buff, 0, 0);
}
