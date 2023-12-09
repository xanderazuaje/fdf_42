/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:11:55 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/05 21:42:54by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <stdlib.h>

t_matrix	*create_matrix(int w, int h, int raw_matrix[w][h][2])
{
	t_matrix *new_matrix;
	t_node *c_node;
	int i;
	int j;

	i = 0;
	j = 0;
	new_matrix = (t_matrix *) malloc(sizeof(t_matrix));
	new_matrix->elements = (t_node *)malloc((w * h) * sizeof(t_node));
	new_matrix->columns = w;
	new_matrix->columns_half = w / 2;
	new_matrix->rows = h;
	new_matrix->rows_half = h / 2;
	if (w % 2 != 0)
		new_matrix->is_col_odd = 1;
	else
		new_matrix->is_col_odd = 0;
	if (h % 2 != 0)
		new_matrix->is_row_odd = 1;
	else
		new_matrix->is_row_odd = 0;

	while (i < h)
	{
		while (j < w)
		{
			c_node = &((new_matrix->elements)[i * w + j]);
			*c_node = create_node(i - (h / 2), j - (w / 2), raw_matrix[i][j][0], raw_matrix[i][j][1]);
			if (j < w - 1)
				c_node->h_next = &((new_matrix->elements)[i * w + j + 1]);
			if (i < h - 1)
				c_node->v_next = &((new_matrix->elements)[i * w + j + w]);
			j++;
		}
		j = 0;
		i++;
	}
	return (new_matrix);
}
