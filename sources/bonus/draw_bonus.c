/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:00:35 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/07 13:08:43 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_square(int x, int y, int size, t_game *game)
{
	int	color;
	int	i;

	color = 0x00FF00;
	i = 0;
	while (i < size)
	{
		ft_put_pixel_minimap(game->frame, x + i, y, color);
		ft_put_pixel_minimap(game->frame, x, y + i, color);
		ft_put_pixel_minimap(game->frame, x + size, y + i, color);
		ft_put_pixel_minimap(game->frame, x + i, y + size, color);
		i++;
	}
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

void	ft_draw_line_continu(t_game *game, float start_x,
	float *ray_x, float *ray_y)
{
	float	cos_angle;
	float	sin_angle;
	int		player_screen_x;
	int		player_screen_y;
	int		screen_x;
	int		screen_y;

	player_screen_x = MINIMAP_OFFSET + (MINIMAP_SIZE / 2);
	player_screen_y = MINIMAP_OFFSET + (MINIMAP_SIZE / 2);
	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	screen_x = player_screen_x + (int)((*ray_x - game->player->x) * BLOCK);
	screen_y = player_screen_y + (int)((*ray_y - game->player->y) * BLOCK);
	ft_put_pixel_minimap(game->frame, screen_x, screen_y, 0xFF0000);
	*ray_x += cos_angle / 10;
	*ray_y += sin_angle / 10;
}

void	ft_draw_line(t_player *player, float start_x, int i, t_game *game)
{
	float	ray_x;
	float	ray_y;

	(void) i;
	ray_x = player->x;
	ray_y = player->y;
	while (1)
	{
		if (ft_is_wall_or_door(game, ray_x, ray_y))
			break ;
		ft_draw_line_continu(game, start_x, &ray_x, &ray_y);
	}
}

void	ft_draw_map(t_game *game)
{
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;
	int	player_screen_x = MINIMAP_OFFSET + (MINIMAP_SIZE / 2);
	int	player_screen_y = MINIMAP_OFFSET + (MINIMAP_SIZE / 2);

	y = 0;
	while (y < game->m_height)
	{
		x = 0;
		while (x < game->m_width)
		{
			if (game->map[y][x] == '1')
			{
				screen_x = player_screen_x + (int)((x - game->player->x) * BLOCK);
				screen_y = player_screen_y + (int)((y - game->player->y) * BLOCK);
				ft_draw_square(screen_x, screen_y, BLOCK, game);
			}
			x++;
		}
		y++;
	}
}
