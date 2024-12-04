/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:24:41 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/04 18:39:11 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write the given char "c" in the standart entry (1).
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
