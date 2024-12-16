/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaychar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:07:19 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/11 11:09:58 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Write the given char "c" in the standart entry (1).
 */
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * @brief Write the given string "s" in the standart entry (1).
 */
int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	i = -1;
	while (s[++i])
		count += write(1, &s[i], 1);
	return (count);
}
