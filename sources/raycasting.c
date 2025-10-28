/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:15:10 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/28 12:06:20 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ft_draw_walls(t_player *player, float start_x, int i, t_game *game)
// {
// 	float	dist = ft_fixed_dist(player->x, player->y, )
// }

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
		// ft_draw_walls(game->player, start_x, i, game);
		start_x += fraction;
		i++;
	}
}
