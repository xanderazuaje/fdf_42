/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minilib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:03:50 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/30 21:02:09 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	set_minilib(void **mlx, void **win, t_img *img)
{
	mlx_put_image_to_window(*mlx, *win, img->img_buff, 0, 0);
	mlx_hook(*win, 2, 1L << 0, key_action, img->img_buff);
	mlx_loop(*mlx);
}
