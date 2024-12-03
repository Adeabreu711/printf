/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:07:48 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/03 17:50:06 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char	ft_getformat(char *s, char *set)
{
	int	i;

	i = -1;
	if (!*(s + 1) || *s != '%')
		return (0);
	while (set[++i])
		if (*(s + 1) == set[i])
			return (set[i]);
	return (0);
}

void	ft_printnumber(void *value, char form)
{
	long long big_buff;

	if (form == 'i')
		big_buff = (int)value;
	if (form == 'd')
		big_buff = (long)value;
	if (form == 'u')
		big_buff = (unsigned long)value;

	ft_putbignbr(big_buff);
}