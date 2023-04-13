/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 05:29:20 by shmimi            #+#    #+#             */
/*   Updated: 2023/04/07 07:20:57 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_weird_chars(char **map, t_player *player)
{
	int		i;
	int		j;
	char	*allowed;

	i = 1;
	j = 1;
	allowed = "PEC01";
	while (map[i])
	{
		while (map[i][j])
		{
			if (!check_weird_chars_2(allowed, map, i, j))
			{
				write(1,
					"Error: Duplicate map components found or no"
					"collectible exists! Please fix your map.\n",
					85);
				free_and_exit3(player);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_player_pos(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	check_path(map, player, player->y, player->x);
}

void	check_path(char **map, t_player *player, int y, int x)
{
	map[y][x] = 'P';
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		check_path(map, player, y, x + 1);
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		check_path(map, player, y - 1, x);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		check_path(map, player, y, x - 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		check_path(map, player, y + 1, x);
}

void	get_exit_pos(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				player->sayonara_x = j;
				player->sayonara_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_collectible_pos(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	player->collectible_x = 0;
	player->collectible_y = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				player->collectible_x = j;
				player->collectible_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
