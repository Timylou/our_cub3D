/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:44:17 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/22 20:04:59 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_clear_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->w_height)
	{
		x = 0;
		while (x < game->w_width)
			ft_put_pixel(game->frame, x++, y, 0x000000);
		y++;
	}
}