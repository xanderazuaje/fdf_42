/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 02:23:36 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/09/20 03:58:29 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_spaces(int *i, const char *str)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
	{
		*i += 1;
	}
}

static void	check_sign(int *i, const char *str, int *sign)
{
	if ((str[*i] == '-' || str[*i] == '+') && ft_isdigit(str[*i + 1]))
	{
		*sign = (str[*i] - 44) * -1;
		*i += 1;
	}
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	skip_spaces(&i, str);
	check_sign(&i, str, &sign);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
			{
				res = (res * 10) + (str[i] - '0');
				i++;
			}
			break ;
		}
		break ;
	}
	return (res * sign);
}
