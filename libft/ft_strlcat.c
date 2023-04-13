/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:15:39 by shmimi            #+#    #+#             */
/*   Updated: 2022/10/28 14:35:28 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendest;

	if (dst == 0 && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	lendest = ft_strlen(dst);
	if (dstsize <= lendest)
		return (ft_strlen(src) + dstsize);
	if (dstsize == 0)
		return (lendest);
	while (i < dstsize - lendest - 1 && src[i])
	{
		dst[lendest + i] = src[i];
		i++;
	}
	dst[lendest + i] = '\0';
	return (lendest + ft_strlen(src));
}
