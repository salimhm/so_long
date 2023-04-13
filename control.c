/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 06:52:46 by shmimi            #+#    #+#             */
/*   Updated: 2023/04/12 04:29:23 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	abc(mlx_key_data_t keycode, void *player_ptr)
{
	t_player		*player;
	static int		counter;
	int				i;
	mlx_texture_t	*texture;

	texture = NULL;
	player = (t_player *)player_ptr;
	i = 0;
	if (keycode.key == MLX_KEY_ESCAPE || keycode.key == 17)
	{
		free_and_exit2(player);
	}
	if (player->map[player->y][player->x + 1] != '1' && keycode.key == MLX_KEY_D
		&& (keycode.action == MLX_REPEAT || keycode.action == MLX_PRESS))
		control_check1(player, &counter, texture);
	if (player->map[player->y - 1][player->x] != '1' && keycode.key == MLX_KEY_W
		&& (keycode.action == MLX_REPEAT || keycode.action == MLX_PRESS))
		control_check2(player, &counter, texture);
	if (player->map[player->y][player->x - 1] != '1' && keycode.key == MLX_KEY_A
		&& (keycode.action == MLX_REPEAT || keycode.action == MLX_PRESS))
		control_check3(player, &counter, texture);
	if (player->map[player->y + 1][player->x] != '1' && keycode.key == MLX_KEY_S
		&& (keycode.action == MLX_REPEAT || keycode.action == MLX_PRESS))
		control_check4(player, &counter, texture);
	open_gate(player, is_collectible_exists(player));
}

int	is_collectible_exists(t_player *player)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (player->map_cpy[i])
	{
		while (player->map_cpy[i][j])
		{
			if (player->map_cpy[i][j] == 'C')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	open_gate(t_player *player, int is_collectible_exists)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./textures/open_door_crypt.png");
	img = mlx_texture_to_image(player->mlx, texture);
	if (!is_collectible_exists)
	{
		mlx_image_to_window(player->mlx, player->texture, player->sayonara_x
			* 32, player->sayonara_y * 32);
		mlx_image_to_window(player->mlx, img, player->sayonara_x * 32,
			player->sayonara_y * 32);
	}
	mlx_delete_texture(texture);
}

void	did_you_win(t_player *player, int is_collectible_exists)
{
	if (player->x == player->sayonara_x && player->y == player->sayonara_y
		&& !is_collectible_exists)
	{
		ft_printf("*************GG!*************\n");
		free_and_exit2(player);
	}
}
