/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proyection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:11:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/08 20:31:43 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

double	my_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_check_wall_door(t_game *game, t_ray *r)
{
	char	map_char;
	t_door	*door;

	map_char = game->map[r->map_y][r->map_x];
	if (map_char == '1')
		return (1);
	else if (map_char == 'D')
	{
		door = ft_get_door(game, r->map_x, r->map_y);
		if (!door || door->state == STATE_CLOSED)
			return (1);
	}
	return (0);
}

void	ft_realistic_height(t_game *game, t_ray *r)
{
	t_player	*player;

	player = game->player;
	if (r->side == 0)
		r->perp_dist = (r->sidedist_x - r->deltadist_x);
	else
		r->perp_dist = (r->sidedist_y - r->deltadist_y);
	if (r->perp_dist < 0.0001)
		r->perp_dist = 0.0001;
	r->line_height = (int)(game->w_height / r->perp_dist);
	r->draw_start = -r->line_height / 2 + game->w_height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = (r->line_height / 2 + game->w_height / 2);
	if (r->draw_end > game->w_height)
		r->draw_end = game->w_height - 1;
	if (r->side == 0)
		r->wall_x = player->y + r->perp_dist * r->ray_dir_y;
	else
		r->wall_x = player->x + r->perp_dist * r->ray_dir_x;
	r->wall_x -= floor(r->wall_x);
}
