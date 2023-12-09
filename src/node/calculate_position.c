/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:15:07 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/05 01:39:19xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <math.h>

void rotate_x(int deg, t_node *node)
{
    double radians = deg * M_PI / 180.0;
    int z = node->relative_pos.z;
    node->transformed_pos.y = node->relative_pos.x * cos(radians) - z * sin(radians);
}

void rotate_y(float deg, t_node *node)
{
    double radians = deg * M_PI / 180.0;
    int z = node->relative_pos.z;
    node->transformed_pos.x = node->relative_pos.y * cos(radians) - z * sin(radians);
    printf("RESULT: %f\n", node->relative_pos.x);
}

void rotate_matrix(int deg_x, int deg_y, t_matrix *matrix)
{
    int i;
    t_node *c_element;

    i = 0;
    while (i < (matrix->columns * matrix->rows))
    {
        c_element = &((matrix->elements)[i]);
        printf("i = %i\n", i);
        rotate_x(deg_x, c_element);
        rotate_y(deg_y, c_element);
        i++;
    }
}

void calculate_position(t_matrix *matrix, t_img *img)
{
    int i;
    t_node *c_element;

    rotate_matrix(45, 0, matrix);
    i = 0;
    while (i < (matrix->columns * matrix->rows))
    {
        c_element = &((matrix->elements)[i]);
        c_element->abs_pos.x = (c_element->transformed_pos.x * matrix->scalar) + (img->w / 2) + matrix->columns_half * matrix->scalar;
        c_element->abs_pos.y = (c_element->transformed_pos.y * matrix->scalar) + (img->h / 2) + matrix->rows_half * matrix->scalar;
        i++;
    }
}

