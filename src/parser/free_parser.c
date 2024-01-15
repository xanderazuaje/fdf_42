/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:18:26 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:58:38 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_parsed(size_t lines_number, size_t words, int **const *parsed)
{
	size_t	j;

	j = 0;
	while (lines_number)
	{
		while (j != words)
		{
			free(parsed[lines_number - 1][j++]);
		}
		free(parsed[lines_number - 1]);
		j = 0;
		lines_number--;
	}
}
