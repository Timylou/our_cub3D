/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:40:38 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/28 12:34:43 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_loop(t_game *game)
{
	ft_move_player(game->player, game);
	ft_clear_frame(game);
	ft_draw_map(game);
	ft_draw_player(game->player->x, game->player->y, 2, game);
	ft_raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame->img, 0, 0);
	usleep(33000);
	return (1);
}
