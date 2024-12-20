/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaychar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:07:19 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/20 13:26:47 by alde-abre        ###   ########.fr       */
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


void ft_displaychar(t_sbuild *out, t_conv *conv, char c)
{
	char	*temp;
	int		size;

	size = conv->witdh + !!c;
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return ;
	if (conv->witdh)
		temp = ft_memset(temp, ' ', size);
	if (!!(conv->flags &  ALIGN_L))
		// temp = ft_memset(temp + );
}


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


