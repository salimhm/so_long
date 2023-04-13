/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:35:15 by shmimi            #+#    #+#             */
/*   Updated: 2023/04/12 20:44:35 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 200
# define HEIGHT 200
# include "/Users/shmimi/MLX42/include/MLX42/MLX42.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct t_player
{
	int			i;
	int			j;
	int			p;
	int			c;
	int			e;
	int			x;
	int			y;
	int			width;
	int			height;
	int			width_x;
	int			height_y;
	int			sayonara_x;
	int			sayonara_y;
	int			collectible_x;
	int			collectible_y;
	char		*line;
	char		*map_init;
	char		**map;
	char		**maps;
	char		**map_cpy;
	mlx_t		*mlx;
	mlx_image_t	*texture;
	mlx_image_t	*img_right;
	mlx_image_t	*img_up;
	mlx_image_t	*img_left;
	mlx_image_t	*img_down;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*door;
	mlx_image_t	*player;
}				t_player;

// Check Map
void			check_map(char **map, t_player *player);
void			check_map2(int first_line, t_player *player, int i, int j);
void			check_dup(t_player *player);
void			map_to_2d(t_player *player, int fd);
void			check_file_extension(char *path, t_player *player);
void			check_file_extension2(t_player *player, char **extension,
					char *ber);
void			check_dup_chars(t_player *player);
void			check_weird_chars(char **map, t_player *player);
void			get_player_pos(char **map, t_player *player);
void			check_path(char **map, t_player *player, int x, int y);
void			get_exit_pos(char **map, t_player *player);
void			get_collectible_pos(char **map, t_player *player);
int				check_weird_chars_2(char *allowed, char **map, int i, int j);
int				check_valid_path(char **map, t_player *player);

// Free
void			free2d(char **arg);
void			free_and_exit(t_player *player);
void			free_and_exit2(t_player *player);
void			free_and_exit3(t_player *player);

// MLX Rendering
void			start_mlx(t_player *player);
void			check_and_get_essentials(t_player *player, char *file);
void			display_walls(t_player *player, int i, int j, int x);
void			display_inside(t_player *player, int i, int j, int x);
void			display_door(t_player *player, int i, int j, int x);
void			get_width_height(char **map, t_player *player);
void			display_collectible(t_player *player, int i, int j, int x);
void			display_player(t_player *player, int i, int j, int x);

// MLX Control
void			abc(mlx_key_data_t keycode, void *player_ptr);
int				is_collectible_exists(t_player *player);
void			open_gate(t_player *player, int is_collectible_exists);
void			did_you_win(t_player *player, int is_collectible_exists);
void			control_check1(t_player *player, int *counter,
					mlx_texture_t *texture);
void			control_check2(t_player *player, int *counter,
					mlx_texture_t *texture);
void			control_check3(t_player *player, int *counter,
					mlx_texture_t *texture);
void			control_check4(t_player *player, int *counter,
					mlx_texture_t *texture);

#endif