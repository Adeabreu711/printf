/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unslngitoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:07:48 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/07 20:01:43 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

/**
 * @return The number of digits in the the given unsigned long "nb".
 */
int	ft_unslngdigitcount(unsigned long nb)
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
 * @return A string corresponding to the given unsigned long "n".
 */
char	*ft_unslngitoa(unsigned long nb)
{
	char	*str;
	int		count;

	count = ft_unslngdigitcount(nb);
	str = ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (count-- > 0)
	{
		str[count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}