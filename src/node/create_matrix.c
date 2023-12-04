/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:11:55 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/04 19:37:07 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <stdio.h>
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
	while (i < h)
	{
		while (j < w)
		{
			printf("%d\n", raw_matrix[i][j]);
			c_node = &new_matrix->elements[i * j];
			*c_node = create_node(w - j, h - i, raw_matrix[i][j],
					0xFFAABB);
			if (j < w - 1)
				c_node->h_next = c_node + sizeof(t_node);
			if (i < h - 1)
				c_node->v_next = c_node + (sizeof(t_node) * w);
			j++;
		}
		j = 0;
		i++;
	}
	return (new_matrix);
}
