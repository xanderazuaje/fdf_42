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


int get_interpolation(int c_dest, int c_origin, double percentage) {
    int dest_red = (c_dest >> 16) & 0xFF;
    int dest_green = (c_dest >> 8) & 0xFF;
    int dest_blue = c_dest & 0xFF;

    int origin_red = (c_origin >> 16) & 0xFF;
    int origin_green = (c_origin >> 8) & 0xFF;
    int origin_blue = c_origin & 0xFF;

    int interpolated_red = (int)(origin_red + percentage * (dest_red - origin_red));
    int interpolated_green = (int)(origin_green + percentage * (dest_green - origin_green));
    int interpolated_blue = (int)(origin_blue + percentage * (dest_blue - origin_blue));

    int interpolated_color = (interpolated_red << 16) | (interpolated_green << 8) | interpolated_blue;


    return interpolated_color;
}
