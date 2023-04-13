/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_extended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 05:54:14 by shmimi            #+#    #+#             */
/*   Updated: 2023/04/12 04:35:33 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	control_check1(t_player *player, int *counter, mlx_texture_t *texture)
{
	if (player->map[player->y][player->x + 1] != 'E')
	{
		texture = mlx_load_png("./textures/Bomberman_right.png");
		player->img_right = mlx_texture_to_image(player->mlx, texture);
		if (player->map_cpy[player->y][player->x + 1] == 'C')
			player->map_cpy[player->y][player->x + 1] = '0';
		(*counter)++;
		ft_printf("%d\n", *counter);
		mlx_image_to_window(player->mlx, player->texture, player->x * 32,
			player->y * 32);
		player->x += 1;
		mlx_image_to_window(player->mlx, player->texture, player->x * 32,
			player->y * 32);
		mlx_image_to_window(player->mlx, player->img_right, player->x * 32,
			player->y * 32);
		mlx_delete_texture(texture);
	}
	else if (player->map[player->y][player->x + 1] == 'E'
			&& !is_collectible_exists(player))
	{
		(*counter)++;
		ft_printf("%d\n", *counter);
		player->x += 1;
		did_you_win(player, is_collectible_exists(player));
	}
}

void	control_check2(t_player *player, int *counter, mlx_texture_t *texture)
{
	if (player->map[player->y - 1][player->x] != 'E')
	{
		texture = mlx_load_png("./textures/Bomberman_up.png");
		player->img_up = mlx_texture_to_image(player->mlx, texture);
		if (player->map_cpy[player->y - 1][player->x] == 'C')
			player->map_cpy[player->y - 1][player->x] = '0';
		(*counter)++;
		ft_printf("%d\n", *counter);
		mlx_image_to_window(player->mlx, player->texture, player->x * 32,
			player->y * 32);
		player->y -= 1;
		mlx_image_to_window(player->mlx, player->texture, player->x * 32,
			player->y * 32);
		mlx_image_to_window(player->mlx, player->img_up, player->x * 32,
			player->y * 32);
		mlx_delete_texture(texture);
	}
	else if (player->map[player->y - 1][player->x] == 'E'
			&& !is_collectible_exists(player))
	{
		(*counter)++;
		ft_printf("%d\n", *counter);
		player->y -= 1;
		did_you_win(player, is_collectible_exists(player));
	}
}

void	control_check3(t_player *player, int *counter, mlx_texture_t *texture)
{
	if (player->map[player->y][player->x - 1] != 'E')
	{
		texture = mlx_load_png("./textures/Bomberman_left.png");
		player->img_left = mlx_texture_to_image(player->mlx, texture);
		if (player->map_cpy[player->y][player->x - 1] == 'C')
			player->map_cpy[player->y][player->x - 1] = '0';
		(*counter)++;
		ft_printf("%d\n", *counter);
		mlx_image_to_window(player->mlx, player->texture, player->x * 32,
			player->y * 32);
		player->x -= 1;
		mlx_image_to_window(player->mlx, player->texture, player->x * 32,
			player->y * 32);
		mlx_image_to_window(player->mlx, player->img_left, player->x * 32,
			player->y * 32);
		mlx_delete_texture(texture);
	}
	else if (player->map[player->y][player->x - 1] == 'E'
			&& !is_collectible_exists(player))
	{
		(*counter)++;
		ft_printf("%d\n", *counter);
		player->x -= 1;
		did_you_win(player, is_collectible_exists(player));
	}
}

void	control_check4(t_player *player, int *counter, mlx_texture_t *texture)
{
	if (player->map[player->y + 1][player->x] != 'E')
	{
		texture = mlx_load_png("./textures/Bomberman_nady.png");
		player->img_down = mlx_texture_to_image(player->mlx, texture);
		if (player->map_cpy[player->y + 1][player->x] == 'C')
			player->map_cpy[player->y + 1][player->x] = '0';
		(*counter)++;
		ft_printf("%d\n", *counter);
		mlx_image_to_window(player->mlx, player->texture, player->x * 32,
			player->y * 32);
		player->y += 1;
		mlx_image_to_window(player->mlx, player->texture, player->x * 32,
			player->y * 32);
		mlx_image_to_window(player->mlx, player->img_down, player->x * 32,
			player->y * 32);
		mlx_delete_texture(texture);
	}
	else if (player->map[player->y + 1][player->x] == 'E'
			&& !is_collectible_exists(player))
	{
		(*counter)++;
		ft_printf("%d\n", *counter);
		player->y += 1;
		did_you_win(player, is_collectible_exists(player));
	}
}
