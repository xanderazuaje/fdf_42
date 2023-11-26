/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_interpolation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 05:18:41 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/26 17:51:12 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

int	get_interpolation(int c_dest, int c_origin, int steps)
{
	return ((c_origin - c_dest) / steps);
}
