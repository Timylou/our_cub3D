/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:40:38 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/03 12:36:30 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_line_2d(t_game *game)
{
	int		i;
	double	fraction;
	double	start_x;

	i = 0;
	fraction = PI / 3 / game->w_width;
	start_x = game->player->angle - PI / 6;
	while (i < game->w_width)
	{
		ft_draw_line(game->player, start_x, i, game);
		start_x += fraction;
		i++;
	}
}

int	ft_loop(t_game *game)
{
	ft_move_player(game->player, game);
	ft_clear_frame(game);
	ft_draw_player(game->player->x, game->player->y, 2, game);
	ft_raycast(game);
	ft_draw_map(game);
	ft_draw_line_2d(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame->img, 0, 0);
	return (1);
}
