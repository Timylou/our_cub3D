/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:02:14 by brturcio          #+#    #+#             */
/*   Updated: 2024/11/19 18:40:45 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_identify_type(va_list args, const char c)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter = ft_putchar(va_arg(args, int));
	if (c == 's')
		counter = ft_putstr(va_arg(args, char *));
	if (c == 'p')
		counter = ft_putpointer(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		counter = ft_putnbrint(va_arg(args, int));
	if (c == 'u')
		counter = ft_putunsig(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		counter = ft_puthexa(va_arg(args, unsigned int), c);
	if (c == '%')
		counter = ft_putchar('%');
	return (counter);
}
