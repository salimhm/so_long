/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:05:17 by shmimi            #+#    #+#             */
/*   Updated: 2022/10/27 00:40:45 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check(char *str, long j, int *size_num, int *i)
{
	while (j > 0)
	{
		str[(*size_num) - 1] = j % 10 + 48;
		j = j / 10;
		(*i)++;
		(*size_num)--;
	}
	while (j)
	{
		if (j < 0)
		{
			str[0] = '-';
			j = j * -1;
		}
		str[(*size_num) - 1] = j % 10 + 48;
		j = j / 10;
		(*i)++;
		(*size_num)--;
	}
}

static char	calc_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		size_num;
	char	*str;
	int		i;
	long	j;
	char	*zero;

	size_num = calc_size(n);
	str = (char *)malloc(size_num * sizeof(char) + 1);
	i = 0;
	j = n;
	if (n == 0)
	{
		zero = (char *)malloc(2 * sizeof(char));
		zero[0] = 0 + 48;
		zero[1] = '\0';
		return (zero);
	}
	if (!str)
		return (0);
	check(str, j, &size_num, &i);
	if (str[0] == '-')
		str[i + 1] = '\0';
	else
		str[i] = '\0';
	return (str);
}
