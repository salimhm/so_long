/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:29:26 by shmimi            #+#    #+#             */
/*   Updated: 2023/04/13 05:19:10 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_walls(t_player *player, int i, int j, int x)
{
	int				y;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	y = 0;
	texture = mlx_load_png("./textures/brick_dark_4_9.png");
	img = mlx_texture_to_image(player->mlx, texture);
	player->wall = img;
	while (player->map[i])
	{
		while (player->map[i][j])
		{
			if (player->map[i][j] == '1')
			{
				y = j * 32;
				mlx_image_to_window(player->mlx, img, y, x);
			}
			j++;
		}
		j = 0;
		i++;
		x = i * 32;
	}
	mlx_delete_texture(texture);
}

void	display_inside(t_player *player, int i, int j, int x)
{
	int				y;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	y = 0;
	texture = mlx_load_png("./textures/grass_flowers_red2.png");
	img = mlx_texture_to_image(player->mlx, texture);
	player->texture = img;
	while (player->map[i])
	{
		while (player->map[i][j])
		{
			if (player->map[i][j] == 'P' || player->map[i][j] == '0'
				|| player->map[i][j] == 'C')
			{
				y = j * 32;
				mlx_image_to_window(player->mlx, img, y, x);
			}
			j++;
		}
		j = 0;
		i++;
		x = i * 32;
	}
	mlx_delete_texture(texture);
}

void	display_door(t_player *player, int i, int j, int x)
{
	int				y;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	y = 0;
	texture = mlx_load_png("./textures/closed_door_crypt.png");
	img = mlx_texture_to_image(player->mlx, texture);
	player->door = img;
	while (player->map[i])
	{
		while (player->map[i][j])
		{
			if (player->map[i][j] ==
				player->map[player->sayonara_y][player->sayonara_x])
			{
				y = j * 32;
				mlx_image_to_window(player->mlx, img, y, x);
			}
			j++;
		}
		j = 0;
		i++;
		x = i * 32;
	}
	mlx_delete_texture(texture);
}

void	display_collectible(t_player *player, int i, int j, int x)
{
	int				y;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	y = 0;
	texture = mlx_load_png("./textures/bomb.png");
	img = mlx_texture_to_image(player->mlx, texture);
	player->collectible = img;
	while (player->map[i])
	{
		while (player->map[i][j])
		{
			if (player->map[i][j] == 'C')
			{
				y = j * 32;
				mlx_image_to_window(player->mlx, img, y, x);
			}
			j++;
		}
		j = 0;
		i++;
		x = i * 32;
	}
	mlx_delete_texture(texture);
}

void	display_player(t_player *player, int i, int j, int x)
{
	int				y;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	y = 0;
	texture = mlx_load_png("./textures/Bomberman_nady.png");
	img = mlx_texture_to_image(player->mlx, texture);
	player->player = img;
	while (player->map[i])
	{
		while (player->map[i][j])
		{
			if (player->map[i][j] == 'P')
			{
				y = j * 32;
				mlx_image_to_window(player->mlx, img, y, x);
			}
			j++;
		}
		j = 0;
		i++;
		x = i * 32;
	}
	mlx_delete_texture(texture);
}
