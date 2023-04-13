/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:15:52 by shmimi            #+#    #+#             */
/*   Updated: 2022/10/28 13:27:07 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*hay;
	size_t	j;
	size_t	k;

	hay = (char *)haystack;
	if (!*needle)
		return (hay);
	if (len == 0)
		return (0);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		k = i;
		while (hay[k] == needle[j] && k < len)
		{
			if (needle[j + 1] == '\0')
				return (hay + i);
			j++;
			k++;
		}
		i++;
	}
	return (0);
}
