/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:13:42 by brturcio          #+#    #+#             */
/*   Updated: 2024/11/19 17:34:14 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsig(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb > 9)
	{
		counter += ft_putunsig(nb / 10);
		counter += ft_putunsig(nb % 10);
	}
	else
		counter += ft_putchar(nb + '0');
	return (counter);
}

int	ft_putnbrint(int nb)
{
	int	counter;

	counter = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		counter += ft_putchar('-');
		counter += ft_putnbrint(nb * -1);
	}
	else if (nb > 9)
	{
		counter += ft_putnbrint(nb / 10);
		counter += ft_putnbrint(nb % 10);
	}
	else
		counter += ft_putchar(nb + '0');
	return (counter);
}
