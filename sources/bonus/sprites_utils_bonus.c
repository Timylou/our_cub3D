/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:26:51 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/08 19:18:35 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_init_sprite(t_game *game, int x, int y)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		ft_error("Malloc sprite failed", game);
	sprite->x = x + 0.5;
	sprite->y = y + 0.5;
	sprite->dist = 0;
	sprite->anim_frame = 0;
	sprite->last_anim_time = 0;
	ft_lstadd_back(&game->sprites, ft_lstnew(sprite));
}

void	ft_lstsort(t_list **list, int (*cmp)(void *, void *))
{
	int		swapped;
	t_list	*current;
	void	*temp_content;

	if (!list || !*list)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current && current->next)
		{
			if (cmp(current->content, current->next->content) > 0)
			{
				temp_content = current->content;
				current->content = current->next->content;
				current->next->content = temp_content;
				swapped = 1;
			}
			current = current->next;
		}
	}
}

void	ft_update_sprite_animation(t_sprite *sprite)
{
	long long	current_time;

	current_time = get_time_in_usec();
	if (current_time - sprite->last_anim_time > ANIM_SPEED)
	{
		sprite->anim_frame++;
		if (sprite->anim_frame > 3)
			sprite->anim_frame = 0;
		sprite->last_anim_time = current_time;
	}
}

int	ft_compare_sprite_dist(void *a, void *b)
{
	t_sprite	*sprite_a;
	t_sprite	*sprite_b;

	sprite_a = (t_sprite *)a;
	sprite_b = (t_sprite *)b;
	if (sprite_a->dist < sprite_b->dist)
		return (1);
	if (sprite_a->dist > sprite_b->dist)
		return (-1);
	return (0);
}

void	ft_sort_sprites(t_game *game)
{
	t_list		*node;
	t_sprite	*sprite;
	t_player	*p;

	if (!game->sprites)
		return ;
	p = game->player;
	node = game->sprites;
	while (node)
	{
		sprite = (t_sprite *)node->content;
		sprite->dist = ((p->x - sprite->x) * (p->x - sprite->x)
				+ (p->y - sprite->y) * (p->y - sprite->y));
		node = node->next;
	}
	ft_lstsort(&game->sprites, ft_compare_sprite_dist);
}
