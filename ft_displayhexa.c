/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayhexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:02:27 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/04 17:36:42 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_displayhexa(unsigned int value, char form)
{
	if (form == 'x')
		ft_putunsnbr_base((unsigned int)value, "0123456789abcdef");
	else if (form == 'X')
		ft_putunsnbr_base((unsigned int)value, "0123456789ABCDEF");
	else if (form == 'p')
	{
		if (!value)
			write(1, "(nil)", 6);
		else
		{
			write(1, "0x", 3);
			ft_putunsnbr_base((unsigned int)value, "0123456789abcdef");
		}
	}
}
