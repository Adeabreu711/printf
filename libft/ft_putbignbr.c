/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbignbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:49:09 by alde-abr          #+#    #+#             */
/*   Updated: 2024/12/03 17:48:29 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Convert the given long long "n" in string and write it
 * in the standart entry.
 */
void	ft_putbignbr(long long n)
{
	char	c;

	if (n == -9223372036854775807)
	{
		write(1, "-9223372036854775807", 21);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	c = (n % 10) + 48;
	if (n > 9)
		ft_putbignbr(n / 10);
	write(1, &c, 1);
}

/*#include <stdio.h>
int	main()
{
	int nb = -2147483648;
	ft_putnbr(nb);
}*/
