/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:39:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/13 01:19:31 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void draw_matrix(t_vars *vars)
{
    t_node *c_node;
    int i;
    int j;

    i = 0;
    j = 0;
    paint_it_black(vars->img, IMG_W, IMG_H);
    while (i < (vars->matrix->columns * vars->matrix->rows))
    {
        c_node = &((vars->matrix->elements)[i]);
        j = 0;
        printf("PRINTED X = %d, PRINTED Y = %d\n", c_node->abs_pos.x, c_node->abs_pos.y);
        if(c_node->h_next)
            draw_line(c_node, c_node->h_next, vars->img);
        if(c_node->v_next)
            draw_line(c_node, c_node->v_next, vars->img);
        i++;
    }
	mlx_put_image_to_window(*(vars->mlx), *(vars->win), vars->img->img_buff, 0, 0);
}