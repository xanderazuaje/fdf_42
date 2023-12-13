/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:06:11 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/13 01:19:09 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->img_addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	paint_it_black(t_img *img, int w, int h)
{
	char	*dst;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while(y < h)
	{
		while(x < w)
		{
			dst = img->img_addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
			*(unsigned int *)dst = 0x000000;
			x++;
		}
		x = 0;
		y++;
	}
}
