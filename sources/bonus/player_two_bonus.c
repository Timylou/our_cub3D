/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_two_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:56:05 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/05 14:19:40 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

// void	ft_check_movement_continue(t_player *p, float ex_x, float ex_y, t_game *g)
// {
// 	t_door	*door;
// 	int		blocked_x;
// 	int		blocked_y;

// 	if (g->map[(int)p->y][(int)p->x] == 'D')
// 	{
// 		door = ft_get_door(g, (int)p->x, (int)p->y);
// 		if (door || door->progress > 0.9)
// 			return ;
// 		blocked_x = (g->map[(int)p->y][(int)ex_x] == 'D');
// 		blocked_y = (g->map[(int)ex_y][(int)p->x] == 'D');
// 		if (blocked_x && blocked_y)
// 		{
// 			p->x = ex_x;
// 			p->y = ex_y;
// 		}
// 		else if (!blocked_x)
// 			p->x = ex_x;
// 		else if (!blocked_y)
// 			p->y = ex_y;
// 	}
// }

void	ft_check_movement_continue(t_player *p, float ex_x, float ex_y, t_game *g)
{
	t_door	*door;
	int		blocked_x;
	int		blocked_y;

	if (g->map[(int)p->y][(int)p->x] == 'D')
	{
		door = ft_get_door(g, (int)p->x, (int)p->y);

		// --- LÓGICA CORREGIDA ---
		// ¿La puerta existe Y está (casi) totalmente abierta?
		if (door && door->progress > 0.9)
		{
			return ; // Sí, entonces deja pasar al jugador.
		}

		// --- CÓDIGO DE BLOQUEO (si la puerta es NULA o está CERRADA) ---

        // (He mejorado tu lógica de slide para que compruebe también muros '1')
		blocked_x = (g->map[(int)p->y][(int)ex_x] == 'D' || g->map[(int)p->y][(int)ex_x] == '1');
		blocked_y = (g->map[(int)ex_y][(int)p->x] == 'D' || g->map[(int)ex_y][(int)p->x] == '1');

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
