/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:42 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/28 16:05:57 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

static t_coords	*create_coords(int x, int y, int z);

t_node	*create_node(int x, int y, int z, char *color)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	ft_bzero(node, sizeof(t_node));
	node->coords = create_coords(x, y, z);
	node->color = parse_color(color);
	return (node);
}

static t_coords	*create_coords(int x, int y, int z)
{
	t_coords	*coords;

	coords = (t_coords *)malloc(sizeof(t_coords));
	coords->x = x;
	coords->y = y;
	coords->z = z;
	return (coords);
}
