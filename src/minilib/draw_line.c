/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:50:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:49:54 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

typedef struct s_errors
{
	int		err;
	int		e2;
}			t_error;

typedef struct s_dl_vars
{
	int		coords[2];
	int		diff[2];
	int		signs[2];
	t_error	error;
	double	percentage;
}			t_dl_vars;

void		init_vars(t_dl_vars *vars, t_node *node1, t_node *node2);

void		bresenham(const t_node *node1, const t_node *node2, t_img *img,
				t_dl_vars *vars);

void		bresenham_helper(t_dl_vars *vars, const t_node *node1,
				const t_node *node2);

static void	adjust_err(const int *diff, int *coords, const int *signs,
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

void	draw_line(t_node *node1, t_node *node2, t_img *img)
{
	t_dl_vars	vars;

	init_vars(&vars, node1, node2);
	bresenham(node1, node2, img, &vars);
	if ((vars.coords[0] < img->w && vars.coords[1] < img->h)
		&& (vars.coords[0] > 0 && vars.coords[1] > 0))
		put_pixel(img, node2->abs_pos.x, node2->abs_pos.y, node2->color);
}

void	bresenham(const t_node *node1, const t_node *node2, t_img *img,
		t_dl_vars *vars)
{
	while (((*vars).coords[0] != node2->abs_pos.x
			|| (*vars).coords[1] != node2->abs_pos.y))
	{
		if (((*vars).coords[0] < img->w && (*vars).coords[1] < img->h)
			&& ((*vars).coords[0] > 0 && (*vars).coords[1] > 0))
		{
			if (node1->color != node2->color)
			{
				bresenham_helper(vars, node1, node2);
				put_pixel(img, (*vars).coords[0], (*vars).coords[1],
					get_interpolation(node2->color, node1->color,
						(*vars).percentage));
			}
			else
				put_pixel(img, (*vars).coords[0], (*vars).coords[1],
					get_interpolation(node2->color, node1->color,
						node2->color));
		}
		(*vars).error.e2 = 2 * (*vars).error.err;
		adjust_err((*vars).diff, (*vars).coords, (*vars).signs, &(*vars).error);
	}
}

void	bresenham_helper(t_dl_vars *vars, const t_node *node1,
		const t_node *node2)
{
	if (abs((*vars).diff[0]) > abs((*vars).diff[1]))
		(*vars).percentage = get_percent(node1->abs_pos.x, node2->abs_pos.x,
				(*vars).coords[0]);
	else
		(*vars).percentage = get_percent(node1->abs_pos.y, node2->abs_pos.y,
				(*vars).coords[1]);
}

void	init_vars(t_dl_vars *vars, t_node *node1, t_node *node2)
{
	vars->coords[0] = node1->abs_pos.x;
	vars->coords[1] = node1->abs_pos.y;
	vars->diff[0] = abs(node2->abs_pos.x - vars->coords[0]);
	vars->diff[1] = abs(node2->abs_pos.y - vars->coords[1]);
	if (vars->coords[0] < node2->abs_pos.x)
		vars->signs[0] = 1;
	else
		vars->signs[0] = -1;
	if (vars->coords[1] < node2->abs_pos.y)
		vars->signs[1] = 1;
	else
		vars->signs[1] = -1;
	vars->error.err = vars->diff[0] - vars->diff[1];
}
