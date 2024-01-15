/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minilib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:34:10 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 03:02:21 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	set_minilib_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, key_action, vars);
	mlx_hook(vars->win, ON_MOUSEDOWN, 1L << 2, mouse_press, vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, 1L << 6, mouse_move, vars);
	mlx_hook(vars->win, ON_MOUSEUP, 1L << 5, mouse_leave, vars);
	mlx_hook(vars->win, 17, (1L << 17), &exittt, vars);
	mlx_loop(vars->mlx);
}
