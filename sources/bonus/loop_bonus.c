/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:40:38 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/08 11:02:03 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
	int	player_screen_x;
	int	player_screen_y;

	if (!ft_get_time())
		return (0);
	if (game->player->key_action == 1 && game->player->can_interact == 1)
	{
		ft_door_status_check(game);
		game->player->can_interact = 0;
	}
	if (game->player->key_action == 0)
		game->player->can_interact = 1;
	ft_move_player(game->player, game);
	ft_clear_frame(game);
	ft_raycast(game);
	ft_draw_minimap_background(game);
	ft_draw_map(game);
	ft_draw_line_2d(game);
	player_screen_x = MINIMAP_OFFSET + (MINIMAP_SIZE / 2);
	player_screen_y = MINIMAP_OFFSET + (MINIMAP_SIZE / 2);
	ft_draw_player(player_screen_x, player_screen_y, 3, game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame->img, 0, 0);
	return (1);
}
