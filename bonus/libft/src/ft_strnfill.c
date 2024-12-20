/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:58:20 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/20 13:11:51 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/**
 * @brief Replace n char of the given string "str" with the given char "c".
 * @return A pointer to the given string "str".
 */
char	*ft_strnfill(char *str, char c, size_t n)
{
	int	i;

	i = -1;
	while (str[++i] && n > 0)
	{
		str[i] = c;
		n--;
	}
	return (str);
}
