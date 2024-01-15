/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:12:12 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:11:50 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../fdf.h"
# include <unistd.h>

typedef struct s_it_vars
{
	char	*line;
	int		***parsed;
}			t_it_vars;

size_t		line_counter(char *file);
int			parse_color(const char *hex, size_t *pos);
int			**parse_line(char *line, size_t n_rows);
size_t		word_counter(char const *s, char c);
char		*get_next_line(int fd);
int			***parse_input(char *file, size_t *lines_number, size_t *words);
void		free_parsed(size_t lines_number, size_t words, int **const *parsed);
int			iterate_and_parse(t_it_vars *it_vars, size_t *lines_number,
				const size_t *words, int fd);
int			***handle_parse_line_error(size_t *lines_number, int ***parsed);
void		handle_parsing_error(int ***parsed, size_t lines, size_t words,
				int fd);
int			ft_ishexa(const char c);
int			is_valid(const char *c, size_t *i);
#endif