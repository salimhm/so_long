/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:13:18 by shmimi            #+#    #+#             */
/*   Updated: 2023/04/12 04:52:44 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free2d(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		arg[i] = NULL;
		i++;
	}
	free(arg);
	arg = NULL;
}

void	free_and_exit(t_player *player)
{
	free2d(player->map);
	free2d(player->maps);
	free2d(player->map_cpy);
	free(player);
	exit(1);
}

void	free_and_exit2(t_player *player)
{
	free2d(player->map);
	free2d(player->maps);
	free2d(player->map_cpy);
	free(player);
	mlx_delete_image(player->mlx, player->texture);
	mlx_delete_image(player->mlx, player->img_right);
	mlx_delete_image(player->mlx, player->img_up);
	mlx_delete_image(player->mlx, player->img_left);
	mlx_delete_image(player->mlx, player->img_down);
	mlx_delete_image(player->mlx, player->wall);
	mlx_delete_image(player->mlx, player->collectible);
	mlx_delete_image(player->mlx, player->door);
	mlx_delete_image(player->mlx, player->player);
	mlx_terminate(player->mlx);
	exit(0);
}

void	free_and_exit3(t_player *player)
{
	free2d(player->map);
	free2d(player->maps);
	free2d(player->map_cpy);
	free(player);
	exit(1);
}
