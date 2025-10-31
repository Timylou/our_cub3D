/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:11:26 by brturcio          #+#    #+#             */
/*   Updated: 2025/10/31 13:14:12 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_struct_inict(t_ray *r)
{
	r->camara = 0;
	r->ray_dir_x = 0;
	r->ray_dir_y = 0;
	r->map_x = 0;
	r->map_y = 0;
	r->step_x = 0;
	r->step_y = 0;
	r->sidedist_x = 0;
	r->sidedist_y = 0;
	r->deltadist_x = 0;
	r->deltadist_y = 0;
	r->side = 0;
	r->hit = 0;
	r->perp_dist = 0;
	r->wall_x = 0;
	r->line_height = 0;
	r->draw_start = 0;
	r->draw_end = 0;
}

double	my_abs(double n)
{
	return ((n < 0) ? -n : n);
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
