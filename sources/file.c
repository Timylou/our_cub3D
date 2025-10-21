/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:08:03 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/14 21:08:04 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_check_name(char *name, char *suffix, t_game *game)
{
	int		len;
	char	s1;
	char	s2;
	char	s3;

	len = 0;
	while (name[len])
		len++;
	if (len < 4)
		ft_error("Map name too short\n", game);
	s1 = suffix[1];
	s2 = suffix[2];
	s3 = suffix[3];
	if (name[len - 4] == '.' && name[len - 3] == s1 && name[len - 2] == s2
		&& name[len - 1] == s3)
		return ;
	ft_error("The map must be a .cub and textures a .xpm\n", game);
}

int	ft_open_file(char *filename, char *suffix, t_game *game)
{
	int	fd;

	ft_check_name(filename, suffix, game);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_error(" : file not found\n", game);
	}
	return (fd);
}
