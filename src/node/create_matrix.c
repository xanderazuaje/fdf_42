/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:11:55 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/05 17:32:26 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <stdlib.h>

void		free_matrix(t_matrix *matrix, int i, int j, int w);

t_matrix	*create_matrix(int w, int h, int raw_matrix[w][h])
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
	new_matrix->rows = h;
	while (i < h)
	{
		while (j < w)
		{
			c_node = &((new_matrix->elements)[(i * w) + j]);
			*c_node = create_node(i - (w / 2), j - (h / 2), raw_matrix[i][j],
					0xFFAABB);
			if (j < w - 1)
				c_node->h_next = &((new_matrix->elements)[(i * j) + 1]);
			if (i < h - 1)
				c_node->v_next = &((new_matrix->elements)[(i * j) + w]);
			//printf("current = %d\n", (int) c_node);	
			//printf("next horizontal= %d\n", (int) c_node->h_next);	
			//printf("next vertical = %d\n", (int) c_node->v_next);	
			j++;
		}
		j = 0;
		i++;
	}
	return (new_matrix);
}
