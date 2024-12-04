/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:12:12 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/04 17:26:36 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

void	printnbr_to_base(long nbr, int base_lenght, char *base)
{
	char	c;

	c = base[nbr % base_lenght];
	if (nbr >= base_lenght)
		printnbr_to_base(nbr / base_lenght, base_lenght, base);
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_lenght;
	long	temp;

	temp = (long)nbr;
	base_lenght = ft_strlen(base);
	if (!check_base(base))
		return ;
	if (nbr < 0)
	{
		temp = -temp;
		write(1, "-", 1);
	}
	printnbr_to_base(temp, base_lenght, base);
}
