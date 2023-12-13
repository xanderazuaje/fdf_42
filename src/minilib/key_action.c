/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:11:56 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/11 17:12:45 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include <stdio.h>

int	key_action(int key, t_img *img)
{
	printf("%d\n", key);
	if (key == ESC)
		exit(0);
	else if (key == NUMPAD_1)
		img->cp.projection = ISOMETRIC;
	else if (key == NUMPAD_2)
		img->cp.projection = CAVALIER;
	else if (key == NUMPAD_3)
		img->cp.projection = SPHERE;
	else if (key == NUMPAD_4)
		img->cp.projection = CONE;
	return (0);
}