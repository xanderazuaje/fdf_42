/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:48:58 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/20 04:08:01 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	word_counter(char const *s, char c)
{
	size_t	i;
	size_t	cw;

	i = 0;
	cw = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
			cw++;
		if (s[i] != c && s[i + 1] == '\0')
			cw++;
		i++;
	}
	return (cw);
}

static void	free_fail(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	start_to_count(const char *s, size_t *i, size_t *end, char c)
{
	while (s[*i] == c)
		*i += 1;
	*end = *i;
	while (s[*i] && s[*i] != c)
		*i += 1;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	end;
	char	**new;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!new)
		return (NULL);
	while (s[i])
	{
		start_to_count(s, &i, &end, c);
		if (i > end)
		{
			new[j] = ft_substr(s, end, i - end);
			if (!new[j])
				return (free_fail(new), NULL);
			j++;
		}
	}
	new[j] = NULL;
	return (new);
}
