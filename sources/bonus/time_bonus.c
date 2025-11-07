/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:41:48 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/07 09:24:17 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static long long	get_time_in_usec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + tv.tv_usec);
}
int	ft_get_time(void)
{
	static long long	last_time;
	long long			current_time;
	long long			time_diff;

	current_time = get_time_in_usec();
	time_diff = current_time - last_time;
	if (time_diff < FRAME_TIME)
		return (0);
	last_time = current_time;
	return (1);
}

