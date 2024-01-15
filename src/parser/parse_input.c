/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:02:21 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:09:41 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	***parse_input(char *file, size_t *lines_number, size_t *words)
{
	t_it_vars	vars;
	int			fd;
	int			is_parse_doable;

	*lines_number = line_counter(file);
	fd = open(file, O_RDONLY);
	vars.line = get_next_line(fd);
	if (!vars.line)
		return (perror("opening file:"), NULL);
	*words = word_counter(vars.line, ' ');
	if (!*words || !*lines_number)
		return (perror("invalid input"), free(vars.line), NULL);
	vars.parsed = (int ***)malloc((*lines_number) * sizeof(int **));
	if (!vars.parsed)
		return (free(vars.line), close(fd), NULL);
	*lines_number = 0;
	while (vars.line)
	{
		is_parse_doable = iterate_and_parse(&vars, lines_number, words, fd);
		if (!is_parse_doable)
			return (NULL);
	}
	close(fd);
	return (vars.parsed);
}
