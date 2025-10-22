/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:15:10 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/23 00:26:56 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_raycast(t_game *game)
{
	float	fraction;
	float	start_x;
	int		i;

	fraction = PI / 3 / game->w_width;
	start_x = game->player->angle - PI / 6;
	i = 0;
	while (i < game->w_width)
	{
		ft_draw_line(game->player, start_x, i, game);
		start_x += fraction;
		i++;
	}
}
