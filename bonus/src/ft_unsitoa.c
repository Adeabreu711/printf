/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:07:48 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/06 17:53:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

/**
 * @return The number of digits in the the given unsigned int "nb".
 */
int	ft_unsdigitcount(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

/**
 * @return A string corresponding to the given unsigned int "n".
 */
char	*ft_unsitoa(unsigned int nb)
{
	char	*str;
	int		count;

	count = ft_unsdigitcount(nb);
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str[count] = '\0';
	while (count-- > 0 && str[count] != '-')
	{
		str[count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
