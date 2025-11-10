/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:29:09 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/10 18:29:32 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	handle_mouse_move(int x, int y, t_game *game)
{
	double	delta_x;
	double	rot_speed;

	(void)y;
	delta_x = (double)x - (game->w_width / 2);
	if (delta_x == 0)
		return (0);
	rot_speed = delta_x * MOUSE_SENSITIVITY;
	game->player->angle += rot_speed;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
	mlx_mouse_move(game->mlx, game->win, game->w_width / 2, game->w_height / 2);
	return (0);
}
