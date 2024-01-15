/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:36:48 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:36:57 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	init_minilib(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (perror("creating mlx"), 0);
	vars->win = mlx_new_window(vars->mlx, IMG_W, IMG_H, "FdF by Sausage");
	if (!vars->win)
		return (perror("creating mlx"), 0);
	vars->img.img_buff = mlx_new_image(vars->mlx, IMG_W, IMG_H);
	if (!vars->img.img_buff)
		return (perror("creating image buff"), 0);
	vars->img.img_addr = mlx_get_data_addr(vars->img.img_buff,
			&vars->img.bits_per_pixel, &vars->img.size_line, &vars->img.endian);
	if (!vars->img.img_addr)
		return (free(vars->img.img_addr), perror("creating img addr"), 0);
	vars->img.w = IMG_W;
	vars->img.h = IMG_H;
	vars->img.is_click_pressed = 0;
	return (1);
}
