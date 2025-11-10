/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:53:12 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/10 18:38:13 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	ft_argc(void)
{
	ft_putstr_fd("./cub3D path_to_map\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_argc());
	game = ft_parse(argv[1]);
	ft_clear_frame(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, ft_handle_release, game);
	mlx_hook(game->win, DestroyNotify, 0, mlx_loop_end, game->mlx);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_mouse_move(game->mlx, game->win, game->w_width / 2, game->w_height / 2);
	mlx_hook(game->win, MotionNotify, PointerMotionMask,
		handle_mouse_move, game);
	mlx_loop_hook(game->mlx, ft_loop, game);
	mlx_loop(game->mlx);
	ft_free_all(game);
	return (0);
}
