/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:15:12 by shmimi            #+#    #+#             */
/*   Updated: 2022/10/27 00:41:27 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pstr, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)pstr)[i] = (unsigned char)c;
		i++;
	}
	return (pstr);
}
