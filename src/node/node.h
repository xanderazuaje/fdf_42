/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:14:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/25 20:54:10 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H
# include <stdlib.h>
# include "../fdf.h"

typedef struct s_coords
{
	int							x;
	int							y;
	int							z;
}								t_coords;

typedef struct s_n_points	t_n_points;

typedef struct s_point
{
	t_coords					*coords;
	int							color;
	t_n_points					*n_points;
	t_coords					*relative_pos;
}								t_point;

typedef struct s_n_points
{
	t_point						*h_next;
	t_point						*v_next;
}								t_n_points;

typedef enum s_point_config
{
	X,
	Y,
	Z,
	COLOR,
	H_NEXT,
	V_NEXT
}								t_point_config;

t_coords						*create_coords(int x, int y, int z);
// Node in-memory CRUD
t_point							*create_node(t_coords *coords, char *color);
void							reset_point(t_point *self);
void							destroy_point(t_point *self);
void							edit_point(t_point_config config,
									t_point *self);
int								parse_color(char *color);

#endif