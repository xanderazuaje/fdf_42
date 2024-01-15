/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:14:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:22:20 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H
# include "../fdf.h"

typedef struct s_img	t_img;
typedef struct s_vars	t_vars;

typedef struct s_coords
{
	double				x;
	double				y;
	double				z;
}						t_coords;

typedef struct s_abs_coords
{
	int					x;
	int					y;
	int					z;
}						t_abs_coords;

typedef struct s_node
{
	struct s_abs_coords	abs_pos;
	struct s_coords		relative_pos;
	struct s_coords		transformed_pos;
	struct s_node		*h_next;
	struct s_node		*v_next;
	int					color;
}						t_node;

typedef struct s_matrix
{
	t_node				*elements;
	size_t				rows;
	size_t				columns;
	double				scalar;
	int					rotation_x;
	int					rotation_y;
	int					mv_x;
	int					off_x;
	int					off_y;
	double				z_scalar;

}						t_matrix;

t_node					create_node(int x, int y, int z, int color);
t_matrix				*create_matrix(size_t w, size_t h, int ***raw_matrix);
void					calculate_position(t_matrix *matrix, t_img *img);
void					draw_matrix(t_vars *vars);
#endif