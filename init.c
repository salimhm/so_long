/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 04:31:32 by shmimi            #+#    #+#             */
/*   Updated: 2023/04/12 18:50:20 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_to_2d(t_player *player, int fd)
{
	player->map_init = ft_calloc(1, 1);
	while (1)
	{
		player->line = get_next_line(fd);
		if (!player->line)
			break ;
		if (ft_strncmp(player->line, "\n", 1) == 0)
		{
			ft_printf("Error: Invalid Map!\n");
			free(player->line);
			free(player->map_init);
			free(player);
			exit(1);
		}
		player->map_init = ft_strjoin(player->map_init, player->line);
		free(player->line);
	}
	player->maps = ft_split(player->map_init, '\n');
	player->map_cpy = ft_split(player->map_init, '\n');
	player->map = ft_split(player->map_init, '\n');
	free(player->map_init);
}

void	start_mlx(t_player *player)
{
	int		i;
	int		j;
	int		x;
	mlx_t	*mlx;

	i = 0;
	j = 0;
	x = 0;
	if (check_valid_path(player->maps, player))
	{
		mlx = mlx_init(player->width_x, player->height_y, "so_long", false);
		player->mlx = mlx;
		display_walls(player, i, j, x);
		display_inside(player, i, j, x);
		display_door(player, i, j, x);
		display_collectible(player, i, j, x);
		display_player(player, i, j, x);
		mlx_key_hook(mlx, &abc, player);
		mlx_loop(mlx);
	}
}

void	check_and_get_essentials(t_player *player, char *file)
{
	check_file_extension(file, player);
	check_map(player->maps, player);
	check_dup_chars(player);
	check_weird_chars(player->maps, player);
	get_width_height(player->maps, player);
	get_player_pos(player->maps, player);
	get_exit_pos(player->maps, player);
	get_collectible_pos(player->maps, player);
}

void	get_width_height(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		i++;
	}
	player->width = j;
	player->height = i;
	player->width_x = j * 32;
	player->height_y = i * 32;
}
