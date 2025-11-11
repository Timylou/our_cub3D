/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:28:47 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/11 10:32:08 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_free_doors(t_game *game)
{
	if (game->doors)
		ft_lstclear(&game->doors, free);
}

void	ft_free_sprites(t_game *game)
{
	if (game->sprites)
		ft_lstclear(&game->sprites, free);
}
