/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:11:24 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/16 20:09:44 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	init_conv(t_conv *out)
{
	ft_memset(out,0, sizeof(t_conv));
	out->precision = -1;
}

int	ft_parseformat(t_conv *out, char *format)
{
	int	i;

	i = -1;
	return (0);
}
