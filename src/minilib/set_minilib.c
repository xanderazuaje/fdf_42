/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minilib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:03:50 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/15 03:49:51 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	set_minilib(t_vars *vars)
{
	mlx_hook(*(vars->win), 2, 1L << 0, key_action, vars);
	mlx_hook(*(vars->win), ON_MOUSEDOWN, 1L << 2, mouse_press, vars);
	mlx_hook(*(vars->win), ON_MOUSEMOVE, 1L << 6, mouse_move, vars);
	mlx_hook(*(vars->win), ON_MOUSEUP, 1L << 5, mouse_leave, vars);
	mlx_loop(*(vars->mlx));
}
