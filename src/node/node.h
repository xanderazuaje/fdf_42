/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:14:39 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/26 18:05:07 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H
# include "../fdf.h"

typedef struct s_coords
{
	int			x;
	int			y;
	int			z;
}				t_coords;

typedef struct s_node	t_node;

typedef struct s_node
{
	t_coords	*coords;
	t_coords	*relative_pos;
	t_node		*h_next;
	t_node		*v_next;
	int			color;
}				t_node;

typedef enum s_node_config
{
	X,
	Y,
	Z,
	COLOR,
	H_NEXT,
	V_NEXT
}				t_node_config;

typedef union u_config_param
{
	int			color_coord_val;
	t_node		*node_location;	
}	t_config_param;

// Data structures

typedef struct s_array
{
	int			len;
	void		*list;
}				t_array;

// Node in-memory CRUD
t_node			*create_node(int x, int y, int z, char *color);
void			reset_node(t_node *self);
void			destroy_node(t_node *self);
void			edit_node(t_node_config config, t_node *self,
					t_config_param new_value);
int				parse_color(char *color);
int				get_interpolation(int c_dest, int c_origin, int steps);

#endif