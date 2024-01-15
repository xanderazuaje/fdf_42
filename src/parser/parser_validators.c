/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:03:35 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/01/15 02:12:05 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_ishexa(const char c)
{
	return (c == 'x' || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')
		|| ft_isdigit(c));
}

int	is_valid(const char *c, size_t *i)
{
	return (ft_ishexa(c[*i]) || c[*i] == ',' || c[*i] == ' ' || c[*i] == '\n'
		|| c[*i] == '-');
}
