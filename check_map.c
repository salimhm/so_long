/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:52:00 by shmimi            #+#    #+#             */
/*   Updated: 2023/04/11 05:25:12 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map2(int first_line, t_player *player, int i, int j)
{
	while (player->map[i])
	{
		if (first_line != (int)ft_strlen(player->map[i]))
		{
			ft_printf("Error: Invalid Map!\n");
			free_and_exit(player);
		}
		if (player->map[i][0] != '1' || player->map[i][ft_strlen(player->map[i])
			- 1] != '1')
		{
			ft_printf("Error: Walls not put correctly!\n");
			free_and_exit(player);
		}
		i++;
	}
	j = 0;
	while (player->map[i - 1][j])
	{
		if (player->map[i - 1][j] != '1')
		{
			ft_printf("Error: Walls not put correctly!\n", j);
			free_and_exit(player);
		}
		j++;
	}
}

void	check_dup(t_player *player)
{
	while (player->map[player->i])
	{
		while (player->map[player->i][player->j])
		{
			if (player->map[player->i][player->j] == 'P')
				player->p++;
			if (player->map[player->i][player->j] == 'C')
				player->c++;
			if (player->map[player->i][player->j] == 'E')
				player->e++;
			player->j++;
		}
		player->j = 0;
		player->i++;
	}
}

int	check_valid_path(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if ((map[player->sayonara_y][player->sayonara_x + 1] == '1'
		|| map[player->sayonara_y][player->sayonara_x + 1] == '0')
		&& (map[player->sayonara_y][player->sayonara_x - 1] == '1'
		|| map[player->sayonara_y][player->sayonara_x - 1] == '0')
		&& (map[player->sayonara_y - 1][player->sayonara_x] == '1'
		|| map[player->sayonara_y - 1][player->sayonara_x] == '0')
		&& (map[player->sayonara_y + 1][player->sayonara_x] == '1'
		|| map[player->sayonara_y + 1][player->sayonara_x] == '0'))
	{
		ft_printf("Error: Player can't exit\n");
		free_and_exit(player);
	}
	if (player->collectible_x || player->collectible_y)
	{
		ft_printf("Error: One or more collectibles still exist\n");
		free_and_exit3(player);
	}
	return (1);
}

void	check_file_extension2(t_player *player, char **extension,
		char *ber)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (extension[1][i] == ber[i])
			i++;
		else
		{
			write(1,
				"Error: Wrong or no file extension, "
				"add .ber to the end of the file\n",
				68);
			free2d(extension);
			free_and_exit3(player);
		}
	}
}
