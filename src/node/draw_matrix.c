/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:39:54 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/05 23:32:41 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void draw_matrix(t_matrix *matrix, t_img *img)
{
    t_node *c_node;
    int i;

    i = 0;
    while (i < (matrix->columns * matrix->rows))
    {
        c_node = &((matrix->elements)[i]);
        if(c_node->h_next)
            draw_line(c_node, c_node->h_next, img);
        if(c_node->v_next)
            draw_line(c_node, c_node->v_next, img);
        i++;
    }
}