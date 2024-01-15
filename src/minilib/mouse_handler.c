/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:34:59 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:35:09 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

// The minus sign is because I use the y-axis inverted with the mouse
int	mouse_press(int button, int x, int y, t_vars *vars)
{
	(void)button;
	(void)x;
	vars->img.is_click_pressed = 1;
	vars->img.cp.current_coord = -y;
	return (0);
}

int	mouse_move(int y, int x, t_vars *vars)
{
	(void)y;
	if (!vars->img.is_click_pressed)
		return (0);
	vars->matrix->mv_x -= (vars->img.cp.current_coord - x);
	if (vars->matrix->mv_x > 360 || vars->matrix->mv_x < -360)
		vars->matrix->mv_x = 0;
	calculate_position(vars->matrix, &vars->img);
	draw_matrix(vars);
	vars->img.cp.current_coord = x;
	return (0);
}

int	mouse_leave(int button, int x, int y, t_vars *vars)
{
	(void)button;
	(void)y;
	vars->img.cp.current_coord = x;
	vars->img.is_click_pressed = 0;
	return (0);
}
