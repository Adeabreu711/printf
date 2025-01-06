/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:07:48 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/06 21:31:21 by alexandre        ###   ########.fr       */
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
