/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:59:57 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/14 20:59:58 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"


t_game	*ft_parse(char *map_name)
{
	t_game	*game;
	int		fd;

	game = NULL;
	fd = ft_open_file(map_name, ".cub", game);
	game = ft_init_game();
	return (game);
}