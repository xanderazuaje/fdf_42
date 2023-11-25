/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:42 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/25 11:56:29 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_point	*create_node(t_coords coords, char *color, t_next_points next_points)
{
	t_point	*node;

	node = (t_point *)malloc(sizeof(t_point));
	node->coords = create_coords(coords.x, coords.y, coords.z);
	node->next_points->h_next = NULL;
	node->next_points->v_next = NULL;
	node->color = parse_color(color);
	return (node);
}