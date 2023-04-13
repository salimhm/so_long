/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:42:03 by shmimi            #+#    #+#             */
/*   Updated: 2023/04/12 04:46:12 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **map, t_player *player)
{
	int	i;
	int	j;
	int	first_line;

	i = 0;
	j = 0;
	first_line = ft_strlen(map[0]);
	while (map[0][j])
	{
		if (map[0][j] != '1')
		{
			ft_printf("Error: Walls not put correctly!\n");
			free_and_exit3(player);
		}
		j++;
	}
	i = 0;
	check_map2(first_line, player, i, j);
}

void	check_file_extension(char *path, t_player *player)
{
	char	**extension;
	char	*ber;

	extension = ft_split(path, '.');
	ber = "ber";
	if (!extension[1])
	{
		write(1,
			"Error: Wrong or no file extension, "
			"add .ber to the end of the file\n",
			68);
		free2d(extension);
		free_and_exit3(player);
	}
	if (ft_strlen(extension[1]) != 3)
	{
		write(1,
			"Error: Wrong or no file extension, "
			"add .ber to the end of the file\n",
			68);
		free2d(extension);
		free_and_exit3(player);
	}
	check_file_extension2(player, extension, ber);
	free2d(extension);
}

void	check_dup_chars(t_player *player)
{
	player->i = 1;
	player->j = 1;
	player->p = 0;
	player->c = 0;
	player->e = 0;
	check_dup(player);
	if (player->p != 1 || player->e != 1 || player->c == 0)
	{
		write(1,
			"Error: Duplicate map components found or no "
			"collectible exists! Please fix your map.\n",
			86);
		free_and_exit3(player);
	}
}

int	check_weird_chars_2(char *allowed, char **map, int i, int j)
{
	int	a;

	a = 0;
	while (allowed[a])
	{
		if (map[i][j] == allowed[a])
			return (1);
		a++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_player	*player;
	int			fd;

	if (ac == 2)
	{
		player = malloc(sizeof(t_player));
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error 404: Map not found!\n");
			free(player);
			exit(1);
		}
		map_to_2d(player, fd);
		check_and_get_essentials(player, av[1]);
		start_mlx(player);
		return (0);
	}
	else
		exit(1);
}
