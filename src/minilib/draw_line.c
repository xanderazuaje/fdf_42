/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:50:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/29 13:06:45xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include "unistd.h"

typedef struct s_errors
{
	int		err;
	int		e2;
}			t_error;

static void	adjust_err(int *diff, int *coords, int *signs,
				t_error *error);

void	draw_line(t_node *node1, t_node *node2, t_img *img)
{
	int		coords[2];
	int		diff[2];
	int		signs[2];
	t_error	error;

	coords[0] = node1->coords->x;
	coords[1] = node1->coords->y;
	diff[0] = abs(node2->coords->x - coords[0]);
	diff[1] = abs(node2->coords->y - coords[1]);
	if (coords[0] < node2->coords->x)
		signs[0] = 1;
	else
		signs[0] = -1;
	if (coords[1] < node2->coords->y)
		signs[1] = 1;
	else
		signs[1] = -1;
	error.err = diff[0] - diff[1];
	while (coords[0] != node2->coords->x && coords[1] != node2->coords->y)
	{
		put_pixel(img, coords[0], coords[1], 0xFFAABB);
		error.e2 = 2 * error.err;
		adjust_err(diff, coords, signs, &error);
	}
}

static void	adjust_err(int *diff, int *coords, int *signs,
		t_error *error)
{
	if (error->e2 > -diff[1])
	{
		error->err -= diff[1];
		coords[0] += signs[0];
	}
	if (error->e2 < diff[0])
	{
		error->err += diff[0];
		coords[1] += signs[1];
	}
}