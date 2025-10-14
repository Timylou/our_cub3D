/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:53:27 by brturcio          #+#    #+#             */
/*   Updated: 2024/11/06 15:26:06 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*recet;
	char	*emiso;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	recet = (char *)dest;
	emiso = (char *)src;
	i = 0;
	while (i < n)
	{
		recet[i] = emiso[i];
		i++;
	}
	return (dest);
}
