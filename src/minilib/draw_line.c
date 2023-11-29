/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:50:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/29 13:06:45 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	draw_line(t_node *node1, t_node *node2, t_img *img)
{
	int	x;
	int	y;
	int	p;
	int	i;

	i = 0;
	x = node1->coords->x - node2->coords->x;
	y = node1->coords->y - node2->coords->y;
	if (y != 0)
		p = x / y;
	else
		p = 0;
	x = node1->coords->x;
	y = node2->coords->y;
	while (x != (node2->coords->x + 1) && y != (node2->coords->y + p))
	{
		put_pixel(img, x, y, 0xFFFFFFFF);
		if (i > p)
		{
			y += p;
			x++;
			i = 0;
			continue ;
		}
		i++;
	}
}
