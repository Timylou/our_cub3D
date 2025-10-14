/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:04:01 by brturcio          #+#    #+#             */
/*   Updated: 2024/11/09 10:39:24 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	p;

	j = 0;
	p = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[j] != '\0')
		j++;
	while (src[p] != '\0')
		p++;
	if (size <= j)
		return (size + p);
	i = 0;
	while (src[i] != '\0' && (j + i) < size - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + p);
}
