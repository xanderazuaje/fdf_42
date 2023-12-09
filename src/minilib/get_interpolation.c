/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_interpolation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 05:18:41 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/07 02:57:45y xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

t_rgb	int_to_rgb(int color);
int		rgb_to_int(t_rgb color);

int	get_interpolation(int c_dest, int c_origin, int steps)
{
	t_rgb			org_color;
	t_rgb			dest_color;

	org_color = int_to_rgb(c_origin);
	dest_color = int_to_rgb(c_dest);
	org_color.r += (org_color.r - dest_color.r) / steps;
	org_color.g += (org_color.g - dest_color.g) / steps;
	org_color.b += (org_color.b - org_color.b) / steps;
	return (rgb_to_int(org_color));
}

t_rgb	int_to_rgb(int color)
{
	t_rgb	to_return;

	to_return.r = color >> 16 & 0xFF;
	to_return.g = color >> 8 & 0xFF;
	to_return.b = color & 0xFF;
	return (to_return);
}

int	rgb_to_int(t_rgb color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}
