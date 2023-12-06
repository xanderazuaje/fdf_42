/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:42 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/05 17:57:17 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <stdlib.h>

static t_coords	create_coords(int x, int y, int z);

t_node	create_node(int x, int y, int z, int color)
{
	t_node	node;

	ft_bzero(&node, sizeof(t_node));
	node.relative_pos = create_coords(x, y, z);
	node.color = color;
	return (node);
}

static t_coords	create_coords(int x, int y, int z)
{
	t_coords	coords;

	coords.x = x;
	coords.y = y;
	coords.z = z;
	return (coords);
}
