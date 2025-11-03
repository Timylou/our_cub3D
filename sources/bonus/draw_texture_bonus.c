/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:14:32 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/01 11:01:20 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_texture_2(t_game *game, t_ray *r, int i, t_info *t)
{
	t->screen_y = r->draw_start;
	while (t->screen_y <= r->draw_end)
	{
		t->tex_y = (int)t->t_pos;
		t->t_pos += t->step;
		if (t->tex_y < 0)
			t->tex_y = 0;
		if (t->tex_y >= t->t_height)
			t->tex_y = t->t_height - 1;
		t->color = ft_get_pixel(t->tex, t->tex_x, t->tex_y);
		if (r->side == 1)
			t->color = (t->color >> 1) & 0x7F7F7F;
		ft_put_pixel(game->frame, i, t->screen_y, t->color);
		t->screen_y++;
	}
}

void	ft_draw_texture(t_game *game, t_ray *r, int i)
{
	t_info	t;

	t.tex = ft_select_texture(game, r);
	t.t_width = t.tex->width;
	t.t_height = t.tex->height;
	t.tex_x = (int)(r->wall_x * (double)t.t_width);
	if (t.tex_x < 0)
		t.tex_x = 0;
	if (t.tex_x >= t.t_width)
		t.tex_x = t.t_width - 1;
	if (r->side == 0 && r->ray_dir_x > 0)
		t.tex_x = t.t_width - t.tex_x - 1;
	if (r->side == 1 && r->ray_dir_y < 0)
		t.tex_x = t.t_width - t.tex_x - 1;
	t.step = (double)t.t_height / (double)r->line_height;
	t.t_pos = (r->draw_start - (game->w_height / 2.0) + (r->line_height / 2.0))
		* t.step;
	ft_draw_texture_2(game, r, i, &t);
}
