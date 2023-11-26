/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:42 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/25 20:54:55 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_point	*create_node(t_coords *coords, char *color)
{
	t_point	*node;

	node = (t_point *)malloc(sizeof(t_point));
	node->coords = coords;
	node->n_points->h_next = NULL;
	node->n_points->v_next = NULL;
	node->color = parse_color(color);
	return (node);
}