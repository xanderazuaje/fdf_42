/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:14:30 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/25 20:43:02 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_coords	*create_coords(int x, int y, int z)
{
	t_coords	*coords;

	coords = (t_coords *)malloc(sizeof(t_coords));
	coords->x = x;
	coords->y = y;
	coords->z = z;
	return (coords);
}