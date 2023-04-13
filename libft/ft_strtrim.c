/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:15:57 by shmimi            #+#    #+#             */
/*   Updated: 2022/10/28 13:04:42 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	lensrc;

	lensrc = (int)ft_strlen(s1) - 1;
	i = 0;
	j = 0;
	while (i < lensrc)
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
		while (j == (int)ft_strlen(set) && s1[i] != set[j])
			return (i);
		if (set[j] == '\0')
			j = 0;
	}
	return (i);
}

static int	second(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > 0)
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
		while (j == (int)ft_strlen(set) && s1[i] != set[j])
		{
			return (i);
		}
		if (set[j] == '\0')
			j = 0;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beginning;
	int		ending;
	char	*new_str;
	int		i;

	if (!s1 || !set)
		return (0);
	if (!*set)
		return (ft_strdup(s1));
	i = 0;
	beginning = first(s1, set);
	ending = second(s1, set);
	if (ending < beginning)
		return ((char *)ft_calloc(sizeof(char), 1));
	new_str = malloc((ending - beginning) * sizeof(char) + 2);
	if (!new_str)
		return (0);
	while (beginning <= ending)
		new_str[i++] = s1[beginning++];
	new_str[i] = '\0';
	return (new_str);
}
