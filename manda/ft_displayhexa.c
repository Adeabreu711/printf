/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayhexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:02:27 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/23 12:33:22 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *base)
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

static int	printnbr_to_base(unsigned long nbr, int base_lenght, char *base)
{
	char	c;
	int		count;

	count = 0;
	c = base[nbr % base_lenght];
	if (nbr >= (unsigned long)base_lenght)
		count = printnbr_to_base(nbr / base_lenght, base_lenght, base);
	return (count + write(1, &c, 1));
}

static int	ft_putunsnbr_base(unsigned long nbr, char *base)
{
	int	base_lenght;
	int	count;

	count = 0;
	base_lenght = ft_pfstrlen(base);
	if (!check_base(base))
		return (0);
	count += printnbr_to_base(nbr, base_lenght, base);
	return (count);
}

int	ft_displayhexa(unsigned int value, char form)
{
	if (form == 'x')
		return (ft_putunsnbr_base((unsigned long)value, "0123456789abcdef"));
	else if (form == 'X')
		return (ft_putunsnbr_base((unsigned long)value, "0123456789ABCDEF"));
	return (0);
}

int	ft_displayptr(unsigned long value)
{
	int	count;

	count = 0;
	if (!value)
		return (write(1, "(nil)", 5));
	else
	{
		count = write(1, "0x", 2);
		count += ft_putunsnbr_base((unsigned long)value, "0123456789abcdef");
	}
	return (count);
}
