/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parsing_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:16:00 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:18:10 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	handle_parsing_error(int ***parsed, size_t lines, size_t words, int fd)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	perror("All lines must have the same amount of columns\n");
	while (i < lines)
	{
		while (j < words)
		{
			free(parsed[i][j]);
			j++;
		}
		free(parsed[i]);
		j = 0;
		i++;
	}
	free(parsed);
	close(fd);
}
