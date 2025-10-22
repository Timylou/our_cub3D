/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:00:35 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/22 22:52:19 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	ft_draw_player(int x, int y, int size, t_game *game)
{
	int	color;
	int	i;

	x = x * BLOCK + BLOCK / 2;
	y = y * BLOCK + BLOCK / 2;
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
