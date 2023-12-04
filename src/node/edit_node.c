/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:40:15 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/04 20:07:07 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void	edit_node(t_node_config config, t_node *self, t_config_param new_value)
{
	if (config == X)
		self->abs_pos.x = new_value.color_coord_val;
	else if (config == Y)
		self->abs_pos.y = new_value.color_coord_val;
	else if (config == Z)
		self->abs_pos.z = new_value.color_coord_val;
	else if (config == COLOR)
		self->color = new_value.color_coord_val;
	else if (config == H_NEXT)
		self->h_next = new_value.node_location;
	else if (config == V_NEXT)
		self->v_next = new_value.node_location;
	return ;
}
