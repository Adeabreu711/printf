/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaychar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:07:19 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/23 19:37:02 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

/**
 * @brief Write the given char "c" in the standart entry (1).
 */
int	ft_putcharlen(char c)
{
	return (write(1, &c, 1));
}


int	ft_pfbuildchar(t_sbuild *out, t_conv *conv, char c)
{
	char	*temp;
	int		size;

	size = !!c;
	if (conv->witdh > size)
		size += conv->witdh - size;
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	if (conv->witdh)
		temp = ft_memset(temp, ' ', size);
	if (!!(conv->flags &  ALIGN_L) && c)
		ft_memset(temp, (int)c, 1);
	else if (c)
		ft_memset(temp + (size - 1), (int)c, 1);
	ft_sb_buildstr(&out, temp, size);
	return (conv->lenght);
}

//si strlen(str) > witdh

/**
 * @brief Write the given string "s" in the standart entry (1).
 */
int	ft_putstrlen(char *s)
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


