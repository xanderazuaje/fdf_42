/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:44:07 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/13 01:20:30 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int mouse_press(int button, int x, int y, t_vars *vars)
{
    (void) button;
    vars->img->is_click_pressed = 1;
    vars->img->cp.current_coords[0] = x;
    vars->img->cp.current_coords[1] = y;
    return (0);
}

int    mouse_move(int y, int x, t_vars *vars)
{
    if(!vars->img->is_click_pressed)
        return (0);
    vars->matrix->mv_x = vars->img->cp.current_coords[0] - x;
    vars->matrix->mv_y = vars->img->cp.current_coords[1] - y;
    printf("X = %d\n", vars->matrix->mv_x);
    printf("Y = %d\n", vars->matrix->mv_y);
    calculate_position(vars->matrix, vars->img);
    draw_matrix(vars);
    return (0);
}

int mouse_leave(int button, int x, int y, t_vars *vars)
{
   (void) button;
   (void) x;
   (void) y;
   vars->img->is_click_pressed = 0; 
   return (0);
}