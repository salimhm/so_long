/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:14:29 by shmimi            #+#    #+#             */
/*   Updated: 2023/04/09 01:49:14 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check(char *nb, int i, int *result, int *sign)
{
	while ((nb[i] >= '0' && nb[i] <= '9') || (nb[i] == '-' || nb[i] == '+'))
	{
		if (nb[i] == ' ')
			i++;
		if (nb[i] == '-')
		{
			if (nb[i + 1] == '-' || nb[i + 1] == '+' || (nb[i - 1] >= '0'
					&& nb[i - 1] <= '9'))
				break ;
			*sign = -1;
			i++;
		}
		if (nb[i] == '+')
		{
			if (nb[i + 1] == '-' || nb[i + 1] == '+' || (nb[i - 1] >= '0'
					&& nb[i - 1] <= '9'))
				break ;
			*sign = 1;
			i++;
		}
		*result *= 10;
		if ((nb[i] >= '0' && nb[i] <= '9'))
			*result += nb[i] - '0';
		i++;
	}
}

int	ft_atoi(const char *str)
{
	char	*nb;
	int		sign;
	int		i;
	int		result;

	nb = (char *)str;
	sign = 1;
	i = 0;
	result = 0;
	while ((nb[i] >= 8 && nb[i] <= 13) || nb[i] == ' ')
		i++;
	check(nb, i, &result, &sign);
	return (result * sign);
}
