/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:12:36 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:12:43 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_color(const char *hex, size_t *pos)
{
	int		val;
	uint8_t	byte;

	val = 0;
	while (hex[*pos] && hex[*pos] != ' ')
	{
		byte = hex[*pos];
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		else
		{
			*pos += 1;
			continue ;
		}
		val = (val << 4) | byte;
		*pos += 1;
	}
	*pos += 1;
	return (val);
}
