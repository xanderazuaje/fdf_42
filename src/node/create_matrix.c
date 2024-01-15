/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:23:19 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:28:23 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <stdlib.h>

typedef struct s_cm_vars
{
	t_matrix	*new_matrix;
	t_node		*c_node;
	size_t		i;
	size_t		j;
}				t_cm_vars;

int				init_matrix(size_t w, size_t h, t_matrix **new_matrix);

void			line_drawer_bresenahm(size_t w, size_t h,
					int **const *raw_matrix, t_cm_vars *cm_vars);

t_matrix	*create_matrix(size_t w, size_t h, int ***raw_matrix)
{
	t_cm_vars	cm_vars;

	cm_vars.j = 0;
	cm_vars.i = 0;
	if (!init_matrix(w, h, &cm_vars.new_matrix))
		return (NULL);
	line_drawer_bresenahm(w, h, raw_matrix, &cm_vars);
	return (cm_vars.new_matrix);
}

// cv is abstration for the necessary vars
void	line_drawer_bresenahm(size_t w, size_t h, int **const *raw_matrix,
		t_cm_vars *cv)
{
	while ((*cv).i < h)
	{
		while ((*cv).j < w)
		{
			(*cv).c_node = &(((*cv).new_matrix->elements)[(*cv).i
					* w + (*cv).j]);
			*(*cv).c_node = create_node((*cv).j - (w / 2),
					(*cv).i - (h / 2),
					raw_matrix[(*cv).i][(*cv).j][0],
					raw_matrix[(*cv).i][(*cv).j][1]);
			if ((*cv).j < w - 1)
				(*cv).c_node->h_next = &(((*cv).new_matrix->elements)[(*cv).i
						* w + (*cv).j + 1]);
			if ((*cv).i < h - 1)
				(*cv).c_node->v_next = &(((*cv).new_matrix->elements)[(*cv).i
						* w + (*cv).j + w]);
			(*cv).j++;
		}
		(*cv).j = 0;
		(*cv).i++;
	}
}

int	init_matrix(size_t w, size_t h, t_matrix **new_matrix)
{
	*new_matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (!*new_matrix)
		return (0);
	ft_bzero(*new_matrix, sizeof(t_matrix));
	(*new_matrix)->elements = (t_node *)malloc((w * h) * sizeof(t_node));
	if (!(*new_matrix)->elements)
		return (free((*new_matrix)), 0);
	(*new_matrix)->columns = w;
	(*new_matrix)->rows = h;
	(*new_matrix)->off_x = 0;
	(*new_matrix)->off_y = 0;
	(*new_matrix)->scalar = 20;
	(*new_matrix)->z_scalar = 0.1;
	return (1);
}
