/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:15:29 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/07 12:42:02 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_put_pixel_minimap(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < MINIMAP_OFFSET || x >= (MINIMAP_OFFSET + MINIMAP_SIZE) ||
		y < MINIMAP_OFFSET || y >= (MINIMAP_OFFSET + MINIMAP_SIZE))
		return ;
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->data + ((y * img->size_line) + (x * (img->bpp / 8)));
	*(unsigned int *)dst = color;
}
void	ft_draw_minimap_background(t_game *game)
{
	int	x;
	int	y;
	int	color;

	color = 0x303030;
	y = MINIMAP_OFFSET;
	while (y < MINIMAP_OFFSET + MINIMAP_SIZE)
	{
		x = MINIMAP_OFFSET;
		while (x < MINIMAP_OFFSET + MINIMAP_SIZE)
		{
			if (x < game->frame->width && y < game->frame->height)
				ft_put_pixel(game->frame, x, y, color);
			x++;
		}
		y++;
	}
}

int	ft_is_wall_or_door(t_game *game, float ray_x, float ray_y)
{
	t_door	*door;

	if (ray_y < 0 || ray_y >= game->m_height || ray_x < 0 || ray_x >= game->m_width)
			return (1);
		if (game->map[(int) ray_y][(int) ray_x] == '1')
			return (1);
		if (game->map[(int) ray_y][(int) ray_x] == 'D')
		{
			door = ft_get_door(game, (int)ray_x, (int)ray_y);
			if (!door || door->state == STATE_CLOSED)
				return (1) ;
		}
	return (0);
}
