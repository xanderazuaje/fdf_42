/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:14:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/03 16:50:17y xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H
# include "../fdf.h"

typedef struct s_img t_img;
typedef struct s_vars t_vars;

typedef struct s_coords
{
	double			x;
	double			y;
	double			z;
}					t_coords;

typedef struct s_abs_coords
{
	int				x;
	int				y;
	int				z;
}					t_abs_coords;

typedef struct s_node
{
	struct s_abs_coords	abs_pos;
	struct s_coords	relative_pos;
	struct s_coords transformed_pos;
	struct s_node	*h_next;
	struct s_node	*v_next;
	int				color;
}					t_node;

typedef struct s_matrix
{
	t_node			*elements;
	int				rows;
	int				rows_half;
	int				is_row_odd;
	int				columns;
	int				columns_half;
	int				is_col_odd;
	int				scalar;
	int				rotation_x;
	int				rotation_y;
	int				mv_x;
	int				mv_y;
}					t_matrix;

typedef enum e_node_config
{
	X,
	Y,
	Z,
	COLOR,
	H_NEXT,
	V_NEXT
}					t_node_config;

typedef union u_config_param
{
	int				color_coord_val;
	t_node			*node_location;
}					t_config_param;

// Node in-memory CRUD
t_node				create_node(int x, int y, int z, int color);
void				reset_node(t_node *self);
void				edit_node(t_node_config config, t_node *self,
						t_config_param new_value);
t_matrix			*create_matrix(int w, int h, int raw_matrix[w][h][2]);
void				calculate_position(t_matrix *matrix, t_img *img);   
void 				draw_matrix(t_vars *vars);
#endif