/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 05:41:19 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/26 17:30:21 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void	reset_node(t_node *self)
{
	self->color = 0xFFFFFFFF;
	self->coords->x = 0;
	self->coords->x = 0;
	self->coords->z = 0;
	self->relative_pos = 0;
	self->h_next = NULL;
	self->v_next = NULL;
}
