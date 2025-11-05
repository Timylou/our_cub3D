/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proyection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:11:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/03 15:53:04 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	my_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
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
