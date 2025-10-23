/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:44:17 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/23 11:08:13 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_clear_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->w_height)
	{
		x = 0;
		while (x < game->w_width)
		{
			if (y < game->w_height / 2)
				ft_put_pixel(game->frame, x, y, game->ceiling_color);
			else
				ft_put_pixel(game->frame, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}