/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exittt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:10:53 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:38:42 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	exittt(t_vars *vars)
{
	free(vars->img.img_addr);
	free(vars->img.img_buff);
	free(vars->matrix->elements);
	free(vars->matrix);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
