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
#define C_X c_element->relative_pos.x
#define C_Y c_element->relative_pos.y
#define C_Z c_element->relative_pos.z

void	rotate_matrix(double deg_x, double deg_y, t_matrix *matrix)
{
	int		i;
	t_node	*c_element;

	deg_x = deg_x * M_PI / 180.0;
	deg_y = deg_y * M_PI / 180.0;

	i = 0;
	while (i < (matrix->columns * matrix->rows))
	{
		c_element = &((matrix->elements)[i]);
		c_element->transformed_pos.x = (C_X * cos(deg_y) + C_Z * sin(deg_y));
		c_element->transformed_pos.y = (C_X * sin(deg_x) * sin(deg_y)) + (C_Y * cos(deg_x)) + (C_Z * sin(deg_x) * (-cos(deg_y)));
		c_element->transformed_pos.z = (C_X * -cos(deg_x) * sin(deg_y)) + (C_Y * sin(deg_x)) + (C_Z * cos(deg_x) * cos(deg_y));
		i++;
	}
	
}

void	calculate_position(t_matrix *matrix, t_img *img)
{
	int		i;
	double		x;
	double		y;
	double		z;
	t_node	*c_element;

	rotate_matrix(matrix->mv_x, matrix->mv_y, matrix);
	i = 0;
	while (i < (matrix->columns * matrix->rows))
	{
		c_element = &((matrix->elements)[i]);
		x = c_element->transformed_pos.x;
		y = c_element->transformed_pos.y;
		z = c_element->transformed_pos.z;

		c_element->abs_pos.x = (((x - y) * cos(0.523599) * matrix->scalar) + (img->w / 2)) + (matrix->columns_half * matrix->scalar);
		c_element->abs_pos.y = (((-z + (x + y) * sin(0.523599)) * matrix->scalar) + (img->w / 2)) + (matrix->columns_half * matrix->scalar);
		/*
		c_element->abs_pos.x = (c_element->transformed_pos.x * matrix->scalar
				+ (img->w / 2)) + matrix->columns_half * matrix->scalar;
		c_element->abs_pos.y = (c_element->transformed_pos.y * matrix->scalar
				+ (img->h / 2)) + matrix->rows_half * matrix->scalar;
		*/
		i++;
	}
}
