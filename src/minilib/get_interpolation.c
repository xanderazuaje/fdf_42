/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_interpolation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:38:07 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:38:09 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	get_interpolation(int c_dest, int c_origin, double percentage)
{
	t_rgb	dest;
	t_rgb	origin;
	t_rgb	interpolated;

	dest.r = (c_dest >> 16) & 0xFF;
	dest.g = (c_dest >> 8) & 0xFF;
	dest.b = c_dest & 0xFF;
	origin.r = (c_origin >> 16) & 0xFF;
	origin.g = (c_origin >> 8) & 0xFF;
	origin.b = c_origin & 0xFF;
	interpolated.r = (int)(origin.r + percentage * (dest.r - origin.r));
	interpolated.g = (int)(origin.g + percentage * (dest.g - origin.g));
	interpolated.b = (int)(origin.b + percentage * (dest.b - origin.b));
	return ((interpolated.r << 16) | (interpolated.g << 8) | interpolated.b);
}
