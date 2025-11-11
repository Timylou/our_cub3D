/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:00:35 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/11 12:25:16 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_init_minimap_data(t_minimap_data *data, t_player *player,
							float start_x, t_game *game)
{
	data->game = game;
	data->ray_x = player->x;
	data->ray_y = player->y;
	data->player_screen_x = MINIMAP_OFFSET + (MINIMAP_SIZE / 2);
	data->player_screen_y = MINIMAP_OFFSET + (MINIMAP_SIZE / 2);
	data->cos_angle = cos(start_x);
	data->sin_angle = sin(start_x);
}

void	ft_draw_player(float x, float y, int size, t_game *game)
{
	int	color;
	int	i;

	color = 0xFF0000;
	i = 0;
	while (i < size)
	{
		ft_put_pixel_minimap(game->frame, (int)x + i, (int)y, color);
		ft_put_pixel_minimap(game->frame, (int)x, (int)y + i, color);
		ft_put_pixel_minimap(game->frame, (int)x + size, (int)y + i, color);
		ft_put_pixel_minimap(game->frame, (int)x + i, (int)y + size, color);
		i++;
	}
}

void	ft_draw_line(t_player *player, float start_x, int i, t_game *game)
{
	t_minimap_data	data;
	int				screen_x;
	int				screen_y;

	(void) i;
	ft_init_minimap_data(&data, player, start_x, game);
	while (1)
	{
		if (ft_is_wall_or_door(game, data.ray_x, data.ray_y))
			break ;
		screen_x = data.player_screen_x
			+ (int)((data.ray_x - game->player->x) * BLOCK);
		screen_y = data.player_screen_y
			+ (int)((data.ray_y - game->player->y) * BLOCK);
		ft_put_pixel_minimap(game->frame, screen_x, screen_y, 0xFF0000);
		data.ray_x += data.cos_angle / 10;
		data.ray_y += data.sin_angle / 10;
	}
}

static void	ft_draw_map_02(t_game *game, int x, int y)
{
	int	screen_x;
	int	screen_y;
	int	player_screen_x;
	int	player_screen_y;

	player_screen_x = MINIMAP_OFFSET + (MINIMAP_SIZE / 2);
	player_screen_y = MINIMAP_OFFSET + (MINIMAP_SIZE / 2);
	screen_x = player_screen_x + (int)((x - game->player->x) * BLOCK);
	screen_y = player_screen_y + (int)((y - game->player->y) * BLOCK);
	ft_draw_square(screen_x, screen_y, BLOCK, game);
}

void	ft_draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->m_height)
	{
		x = 0;
		while (x < game->m_width)
		{
			if (game->map[y][x] == '1')
				ft_draw_map_02(game, x, y);
			x++;
		}
		y++;
	}
}
