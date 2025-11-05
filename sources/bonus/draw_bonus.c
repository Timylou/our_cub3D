/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:00:35 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/03 15:31:10 by brturcio         ###   ########.fr       */
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
		ft_put_pixel(game->frame, x + i, y, color);
		ft_put_pixel(game->frame, x, y + i, color);
		ft_put_pixel(game->frame, x + size, y + i, color);
		ft_put_pixel(game->frame, x + i, y + size, color);
		i++;
	}
}

void	ft_draw_player(float x, float y, int size, t_game *game)
{
	int	color;
	int	i;

	x = x * BLOCK;
	y = y * BLOCK;
	color = 0xFF0000;
	i = 0;
	while (i < size)
	{
		ft_put_pixel(game->frame, x + i, y, color);
		ft_put_pixel(game->frame, x, y + i, color);
		ft_put_pixel(game->frame, x + size, y + i, color);
		ft_put_pixel(game->frame, x + i, y + size, color);
		i++;
	}
}

void	ft_draw_line(t_player *player, float start_x, int i, t_game *game)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;

	(void) i;
	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;
	while (game->map[(int) ray_y][(int) ray_x] != '1')
	{
		ft_put_pixel(game->frame, ray_x * BLOCK, ray_y * BLOCK, 0xFF0000);
		ray_x += cos_angle / 10;
		ray_y += sin_angle / 10;
	}
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
				ft_draw_square(x * BLOCK, y * BLOCK, BLOCK, game);
			x++;
		}
		y++;
	}
}
