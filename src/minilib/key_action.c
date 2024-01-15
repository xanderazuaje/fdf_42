/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:11:56 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:36:22 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static int	general_controls(int key, t_vars *vars);
static int	arrow_controls(int key, t_vars *vars);
static int	z_scalar_controls(int key, t_vars *vars);

int	key_action(int key, t_vars *vars)
{
	int	is_used;

	is_used = general_controls(key, vars);
	is_used += arrow_controls(key, vars);
	is_used += z_scalar_controls(key, vars);
	if (is_used > 0)
	{
		calculate_position(vars->matrix, &vars->img);
		draw_matrix(vars);
	}
	return (0);
}

static int	general_controls(int key, t_vars *vars)
{
	if (key == ESC)
		exittt(vars);
	else if (key == NUMPAD_1)
		vars->img.cp.projection = ISOMETRIC;
	else if (key == NUMPAD_2)
		vars->img.cp.projection = IDK;
	else if (key == NUMPAD_3)
		vars->img.cp.projection = LINEAR;
	else if (key == MINUS)
	{
		if (-vars->matrix->scalar * 2 * 0.1 >= INT_MIN)
			vars->matrix->scalar -= vars->matrix->scalar * 0.1;
	}
	else if (key == PLUS)
	{
		if (vars->matrix->scalar * 2 * 0.1 <= INT_MAX)
			vars->matrix->scalar += vars->matrix->scalar * 0.1;
	}
	else
		return (0);
	return (1);
}

static int	arrow_controls(int key, t_vars *vars)
{
	if (key == ARROW_DOWN)
	{
		if (vars->matrix->off_y - 10 >= INT_MIN)
			return (vars->matrix->off_y -= 10, 1);
	}
	else if (key == ARROW_LEFT)
	{
		if (vars->matrix->off_x - 10 >= INT_MIN)
			return (vars->matrix->off_x -= 10, 1);
	}
	else if (key == ARROW_UP)
	{
		if (vars->matrix->off_y + 10 <= INT_MAX)
			return (vars->matrix->off_y += 10, 1);
	}
	else if (key == ARROW_RIGHT)
	{
		if (vars->matrix->off_x - 10 <= INT_MAX)
			return (vars->matrix->off_x += 10, 0);
	}
	return (0);
}

static int	z_scalar_controls(int key, t_vars *vars)
{
	if (key == KEY_X)
	{
		if (vars->matrix->z_scalar - 0.1 <= 0)
			return (vars->matrix->z_scalar = 0, 1);
		return (vars->matrix->z_scalar -= 0.1, 1);
	}
	else if (key == KEY_Z)
		return (vars->matrix->z_scalar += 0.1, 1);
	return (0);
}
