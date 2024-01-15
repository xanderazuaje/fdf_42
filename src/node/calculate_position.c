/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:15:07 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:32:28 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <math.h>

void	project_isometric(const t_matrix *matrix, const t_img *img,
			t_coords coords, t_node *c_element);

void	project_linear(const t_matrix *matrix, const t_img *img,
			t_coords coords, t_node *c_element);

void	project_idk(const t_matrix *matrix, const t_img *img, t_coords coords,
			t_node *c_element);

void	rotate_matrix(double deg_y, t_matrix *matrix)
{
	size_t	i;
	t_node	*c_element;

	deg_y = deg_y * M_PI / 180.0;
	i = 0;
	while (i < (matrix->columns * matrix->rows))
	{
		c_element = &((matrix->elements)[i]);
		c_element->transformed_pos.x = c_element->relative_pos.x * cos(deg_y)
			+ c_element->relative_pos.z * sin(deg_y) * matrix->z_scalar;
		c_element->transformed_pos.y = c_element->relative_pos.y;
		c_element->transformed_pos.z = c_element->relative_pos.x * -sin(deg_y)
			+ (c_element->relative_pos.z * cos(deg_y) * matrix->z_scalar);
		i++;
	}
}

void	calculate_position(t_matrix *matrix, t_img *img)
{
	size_t		i;
	t_coords	coords;
	t_node		*c_element;

	rotate_matrix(matrix->mv_x, matrix);
	i = 0;
	while (i < (matrix->columns * matrix->rows))
	{
		c_element = &((matrix->elements)[i]);
		coords.x = c_element->transformed_pos.x;
		coords.y = c_element->transformed_pos.y;
		coords.z = c_element->transformed_pos.z;
		if (img->cp.projection == ISOMETRIC)
			project_isometric(matrix, img, coords, c_element);
		else if (img->cp.projection == IDK)
			project_idk(matrix, img, coords, c_element);
		else
			project_linear(matrix, img, coords, c_element);
		i++;
	}
}

void	project_idk(const t_matrix *matrix, const t_img *img, t_coords coords,
		t_node *c_element)
{
	c_element->abs_pos.x = (int)((coords.x - coords.y) * (matrix->scalar)
			+ ((double)img->w / 2)) + matrix->off_x;
	c_element->abs_pos.y = (int)((-coords.z * (coords.x + coords.y)
				* (matrix->scalar) + ((double)img->h / 2) + matrix->off_y));
}

void	project_linear(const t_matrix *matrix, const t_img *img,
		t_coords coords, t_node *c_element)
{
	c_element->abs_pos.x = (int)((coords.x - coords.y) * (matrix->scalar)
			+ ((double)img->w / 2) + matrix->off_x);
	c_element->abs_pos.y = (int)(-coords.z + (coords.x + coords.y)
			* (matrix->scalar) + ((double)img->h / 2) + matrix->off_y);
}

void	project_isometric(const t_matrix *matrix, const t_img *img,
		t_coords coords, t_node *c_element)
{
	c_element->abs_pos.x = (int)((coords.x - coords.y) * cos(0.523599)
			* (matrix->scalar) + ((double)img->w / 2)) + matrix->off_x;
	c_element->abs_pos.y = (int)(((-coords.z + (coords.x + coords.y)
					* sin(0.523599)) * (matrix->scalar) + ((double)img->h / 2)
				+ matrix->off_y));
}
