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

void	calculate_position(t_matrix *matrix, t_img *img)
{
	int i;
	t_node *c_element;

	i = 0;
	while (i < (matrix->columns * matrix->rows))
	{
		c_element = &((matrix->elements)[i]);
		c_element->abs_pos.x = (img->w / 2) + (c_element->relative_pos.x * matrix->scalar) - (matrix->columns * matrix->scalar / 2);
		c_element->abs_pos.y = (img->h / 2) + (c_element->relative_pos.y * matrix->scalar) - (matrix->rows * matrix->scalar / 2);
		//printf("x = %d, y = %d, ", c_element->abs_pos.x, c_element->abs_pos.y);
		c_element->abs_pos.y -= c_element->relative_pos.z * (matrix->scalar / 2);
		//printf("z = %d\n", c_element->abs_pos.y);
		//printf("Relative x = %d, y = %d, z = %d \n", c_element->relative_pos.x, c_element->relative_pos.y, c_element->relative_pos.z);
		i++;
	}
}