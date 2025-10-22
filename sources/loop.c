/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:40:38 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/22 22:51:58 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_loop(t_game *game)
{
	ft_move_player(game->player, game);
	ft_clear_frame(game);
	ft_draw_map(game);
	ft_draw_player(game->player->x, game->player->y, 2, game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame->img, 0, 0);
	return (1);
}