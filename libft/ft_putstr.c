/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:18:15 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/04 18:25:03 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write the given string "s" in the standart entry (1).
 */
void	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 7);
		return ;
	}
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}
