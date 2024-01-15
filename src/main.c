/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:38:26 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 03:12:23 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	end_with_fdf(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	str = str + len - 4;
	if (ft_strncmp(str, ".fdf", 4) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	size_t	lines_number;
	size_t	words;
	int		***parsed;
	t_vars	vars;

	if (argc != 2)
		return (perror("Not exactly 1 parameter"), 0);
	if (!end_with_fdf(argv[1]))
		return (perror("wrong file extension"), 0);
	parsed = parse_input(argv[1], &lines_number, &words);
	if (!parsed)
		return (0);
	if (!init_minilib(&vars))
		return (free(parsed), 0);
	vars.matrix = create_matrix(words, lines_number, parsed);
	free_parsed(lines_number, words, parsed);
	free(parsed);
	if (!vars.matrix)
		return (perror("error creating matrix"), 0);
	vars.img.cp.projection = ISOMETRIC;
	calculate_position(vars.matrix, &vars.img);
	draw_matrix(&vars);
	set_minilib_hooks(&vars);
	return (0);
}
