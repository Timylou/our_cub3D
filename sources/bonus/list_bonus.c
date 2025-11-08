/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:44:37 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/08 14:55:03 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_free_lst(char *msg, t_list *lst, t_game *game)
{
	ft_lstclear(&lst, free);
	ft_error(msg, game);
}

static void	ft_check_width(t_list *tmp, int width, t_list *lst, t_game *game)
{
	int		i;
	char	*new_line;
	int		len;

	len = ft_strlen(tmp->content);
	if (len < 3)
		ft_free_lst("A line is too short in the map\n", lst, game);
	if (len == width)
		return ;
	new_line = malloc(sizeof(char) * width);
	if (!new_line)
		ft_free_lst("Malloc Error\n", lst, game);
	i = -1;
	while (++i < len)
		new_line[i] = ((char *)tmp->content)[i];
	while (i < width - 1)
		new_line[i++] = ' ';
	new_line[i] = 0;
	free(tmp->content);
	tmp->content = new_line;
}

static void	ft_free_lst_no_content(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

t_list	*ft_handle_lst_continue(t_game *game, t_list *tmp, int *i)
{
	int		x;
	char	*line;

	line = (char *)tmp->content;
	game->map[*i] = line;
	x = 0;
	while (line[x])
	{
		if (line[x] == 'D')
			ft_is_door(game, x, *i);
		else if (line[x] == 'A')
		{
			ft_init_sprite(game, x, *i);
			line[x] = '0';
		}
		x++;
	}
	(*i)++;
	return (tmp->next);
}

void	ft_handle_lst(t_list *lst, int width, int height, t_game *game)
{
	t_list	*tmp;
	int		i;

	if (height < 3 || width < 3)
		ft_free_lst("Map too small\n", lst, game);
	tmp = lst;
	while (tmp)
	{
		ft_check_width(tmp, width, lst, game);
		tmp = tmp->next;
	}
	game->map = malloc(sizeof(char *) * height);
	if (!game->map)
		ft_free_lst("Malloc Error\n", lst, game);
	i = 0;
	tmp = lst;
	while (tmp)
		tmp = ft_handle_lst_continue(game, tmp, &i);
	game->m_width = width;
	game->m_height = height;
	ft_free_lst_no_content(lst);
}
