/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaynumbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:33:00 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/04 18:55:20 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

/**
 * @brief Convert the given unsigned int "n" in a string and write it
 * in the standart entry.
 */
int	ft_putunsnbr(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	c = (n % 10) + 48;
	if (n > 9)
		count = ft_putunsnbr(n / 10);
	return (count + write(1, &c, 1));
}

/**
 * @brief Convert the given int "n" in a string and write it
 * in the standart entry.
 */
int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count = (write(1, "-", 1));
		n = -n;
	}
	c = (n % 10) + 48;
	if (n > 9)
		count += ft_putnbr(n / 10);
	return (count + write(1, &c, 1));
}

int	ft_displaynumbers(long value, char form)
{
	if (form == 'i' || form == 'd')
		return (ft_putnbr((int)value));
	if (form == 'u')
		return (ft_putunsnbr((unsigned int)value));
	return (0);
}
