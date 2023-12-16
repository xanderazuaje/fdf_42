/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:39:26 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/12/16 15:38:32 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

double get_percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    if(distance == 0)
        return (1.0);
    return ((placement / distance));
}