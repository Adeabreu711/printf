/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaynumbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:33:00 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/04 16:56:09 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Convert the given unsigned int "n" in a string and write it
 * in the standart entry.
 */
void	ft_putunsnbr(unsigned int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	c = (n % 10) + 48;
	if (n > 9)
		ft_putunsnbr(n / 10);
	write(1, &c, 1);
}

/**
 * @brief Convert the given int "n" in a string and write it
 * in the standart entry.
 */
void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 12);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	c = (n % 10) + 48;
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &c, 1);
}

void	ft_displaynumbers(long value, char form)
{
	if (form == 'i' || form == 'd')
		ft_putnbr((int)value);
	if (form == 'u')
		ft_putunsnbr((unsigned int)value);
}
