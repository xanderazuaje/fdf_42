/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:11:56 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/15 13:06:50 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include <stdio.h>

int	key_action(int key, t_vars *vars)
{
	printf("%d\n", key);
	if (key == ESC)
		exit(0);
	else if (key == NUMPAD_1)
		vars->img->cp.projection = ISOMETRIC;
	else if (key == NUMPAD_2)
		vars->img->cp.projection = CAVALIER;
	else if (key == NUMPAD_3)
		vars->img->cp.projection = SPHERE;
	else if (key == NUMPAD_4)
		vars->img->cp.projection = CONE;
	else if (key == MINUS)
	{
		if(-vars->matrix->scalar * 2 * 0.1 < INT_MIN)
			return (0);
		printf("%f\n", vars->matrix->scalar);
		vars->matrix->scalar -= vars->matrix->scalar * 0.1;
		calculate_position(vars->matrix, vars->img);
		draw_matrix(vars);
	}
	else if (key == PLUS)
	{
		if(vars->matrix->scalar * 2 * 0.1 > INT_MAX)
			return (0);
		vars->matrix->scalar += vars->matrix->scalar * 0.1;
		printf("%f\n", vars->matrix->scalar);
		calculate_position(vars->matrix, vars->img);
		draw_matrix(vars);
	}
	return (0);
}