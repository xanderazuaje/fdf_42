/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parse_line_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:13:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:13:40 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	***handle_parse_line_error(size_t *lines_number, int ***parsed)
{
	if (*lines_number)
	{
		while (*lines_number > 0)
		{
			free(*parsed[*lines_number]);
			*lines_number -= 1;
		}
		free(*parsed[*lines_number]);
	}
	free(*parsed);
	system("leaks fdf");
	return (NULL);
}
