/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:05:41 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:05:55 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			**error_free(size_t i, int ***to_return);

int			is_doable(const char *line, size_t n_rows, int ***to_return);

size_t	word_counter(char const *s, char c)
{
	size_t	i;
	size_t	cw;

	cw = ((i = 0), 0);
	while (s[i] == c)
	{
		i++;
	}
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] == c && s[i + 1] == c)
		{
			i++;
			continue ;
		}
		if (s[i + 1] == c && s[i] != c)
			cw++;
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == '\n'))
			cw++;
		i++;
	}
	return (cw);
}

size_t	line_counter(char *file)
{
	char	*line;
	size_t	i;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

int	**parse_line(char *line, size_t n_rows)
{
	int	**to_return ;

	if (ft_strlen(line) <= 1)
		return (perror("invalid input"), NULL);
	to_return = (int **)malloc(n_rows * sizeof(int *));
	if (!to_return)
		return (NULL);
	if (!is_doable(line, n_rows, &to_return))
		return (NULL);
	return (to_return);
}

int	is_doable(const char *line, size_t n_rows, int ***to_return)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < n_rows)
	{
		if (!is_valid(line, &i))
			return (perror("invalid input:"), error_free(i, to_return), 0);
		(*to_return)[i] = (int *)malloc(2 * sizeof(int *));
		if (!(*to_return)[i])
			return (perror("malloc:"), error_free(i, to_return), 0);
		if (ft_isdigit(line[j]) || line[j] == ' ' || line[j] == '\n'
			|| line[j] == '-')
			(*to_return)[i][0] = ft_atoi_pos(line, &j);
		else
			return (perror("invalid input:"), error_free(i, to_return), 0);
		if (line[j] == ',')
			(*to_return)[i][1] = parse_color(line, &j);
		else
			(*to_return)[i][1] = 0xFFFFFF;
		i++;
	}
	return (1);
}

int	**error_free(size_t i, int ***to_return)
{
	while (i > 0)
		free(*to_return[i--]);
	free((*to_return)[i]);
	free(*to_return);
	return (NULL);
}
