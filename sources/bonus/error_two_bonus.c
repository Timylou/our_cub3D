/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:28:47 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/04 12:31:50 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_free_doors(t_game *game)
{
	t_list	*ptr;
	t_list	*next;

	ptr = game->doors;
	while (ptr)
	{
		next = ptr->next;
		if (ptr->content)
			free(ptr->content);
		free(ptr);
		ptr = next;
	}
	game->doors = NULL;
}
