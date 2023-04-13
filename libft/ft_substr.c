/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:15:59 by shmimi            #+#    #+#             */
/*   Updated: 2022/10/28 04:42:06 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str || !s)
		return (0);
	while (start < ft_strlen(s) && s[i] != '\0' && i < len)
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}
