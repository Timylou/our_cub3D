/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_two_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:56:05 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/08 12:42:43 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_check_movement_continue(t_player *p, float ex_x,
									float ex_y, t_game *g)
{
	t_door	*door;
	int		blocked_x;
	int		blocked_y;

	if (g->map[(int)p->y][(int)p->x] == 'D')
	{
		door = ft_get_door(g, (int)p->x, (int)p->y);
		if (door && door->state == STATE_OPEN)
			return ;
		blocked_x = (g->map[(int)p->y][(int)ex_x] == 'D');
		blocked_y = (g->map[(int)ex_y][(int)p->x] == 'D');
		if (blocked_x && blocked_y)
		{
			p->x = ex_x;
			p->y = ex_y;
		}
		else if (!blocked_x)
			p->x = ex_x;
		else if (!blocked_y)
			p->y = ex_y;
	}
}
