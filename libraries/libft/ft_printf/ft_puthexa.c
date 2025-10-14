/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:16:14 by brturcio          #+#    #+#             */
/*   Updated: 2024/11/23 10:51:37 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	int				counter;
	unsigned long	addr;

	counter = 0;
	addr = (unsigned long)ptr;
	if (ptr == NULL)
		return (counter += ft_putstr("(nil)"));
	counter += ft_putstr("0x");
	counter += ft_puthexa_long(addr);
	return (counter);
}

int	ft_puthexa_long(unsigned long addr)
{
	int	counter;

	counter = 0;
	if (addr >= 16)
	{
		counter += ft_puthexa_long(addr / 16);
		counter += ft_puthexa_long(addr % 16);
	}
	else
	{
		if (addr < 10)
			counter += ft_putchar(addr + '0');
		else
			counter += ft_putchar(addr - 10 + 'a');
	}
	return (counter);
}

int	ft_puthexa(unsigned int nb, const char c)
{
	int	counter;

	counter = 0;
	if (nb >= 16)
	{
		counter += ft_puthexa(nb / 16, c);
		counter += ft_puthexa(nb % 16, c);
	}
	else
	{
		if (nb < 10)
			counter += ft_putchar(nb + '0');
		else
		{
			if (c == 'x')
				counter += ft_putchar(nb - 10 + 'a');
			else
				counter += ft_putchar(nb - 10 + 'A');
		}
	}
	return (counter);
}
