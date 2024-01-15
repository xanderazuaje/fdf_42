/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_and_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:52:32 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:08:36 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	iterate_and_parse(t_it_vars *it_vars, size_t *lines_number,
		const size_t *words, int fd)
{
	it_vars->parsed[*lines_number] = parse_line(it_vars->line, *words);
	if (!it_vars->parsed[*lines_number])
	{
		handle_parse_line_error(lines_number, it_vars->parsed);
		return (0);
	}
	free(it_vars->line);
	*lines_number += 1;
	it_vars->line = get_next_line(fd);
	if (it_vars->line && word_counter(it_vars->line, ' ') != *words)
	{
		handle_parsing_error(it_vars->parsed, *lines_number, *words, fd);
		free(it_vars->line);
		return (0);
	}
	return (1);
}
