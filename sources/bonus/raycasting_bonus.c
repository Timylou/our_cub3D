/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:15:10 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/08 20:32:09 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_struct_inict(t_ray *r)
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

static void	ft_inict_camara(t_game *game, t_ray *r, int x)
{
	t_player	*p;

	p = game->player;
	r->camara = 2.0 * x / (double)game->w_width - 1.0;
	r->ray_dir_x = p->dir_x + p->plane_x * r->camara;
	r->ray_dir_y = p->dir_y + p->plane_y * r->camara;
	r->map_x = (int)p->x;
	r->map_y = (int)p->y;
	r->deltadist_x = my_abs(1 / r->ray_dir_x);
	r->deltadist_y = my_abs(1 / r->ray_dir_y);
}

static void	ft_inict_sidedist(t_ray *r, t_player *player)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (player->x - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - player->x) * r->deltadist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (player->y - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - player->y) * r->deltadist_y;
	}
}

static void	ft_inict_dda(t_game *game, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->deltadist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist_y += r->deltadist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->map_y < 0 || r->map_y >= game->m_height
			|| r->map_x < 0 || r->map_x >= game->m_width)
			r->hit = 1;
		else if (ft_check_wall_door(game, r))
			r->hit = 1;
	}
}

void	ft_raycast(t_game *game)
{
	t_ray	r;
	int		i;

	i = 0;
	while (i < game->w_width)
	{
		ft_struct_inict(&r);
		ft_inict_camara(game, &r, i);
		ft_inict_sidedist(&r, game->player);
		ft_inict_dda(game, &r);
		ft_realistic_height(game, &r);
		game->z_buffer[i] = r.perp_dist;
		ft_draw_texture(game, &r, i);
		i++;
	}
}
