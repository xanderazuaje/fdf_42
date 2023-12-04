/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:11:56 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/30 14:18:48 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include <stdio.h>

int	key_action(int key, t_img *img)
{
	printf("%d\n", key);
	if (key == 53)
		exit(0);
	(void)img;
	return (0);
}