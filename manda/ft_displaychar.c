/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaychar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:07:19 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/23 12:31:11 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Write the given char "c" in the standart entry (1).
 */
int	ft_pfputchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * @brief Write the given string "s" in the standart entry (1).
 */
int	ft_pfputstr(char *s)
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
