/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:07:19 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/30 17:17:12 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

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
	if (!!(conv->flags & ALIGN_L) && c)
		ft_memset(temp, (int)c, 1);
	else if (c)
		ft_memset(temp + (size - 1), (int)c, 1);
	ft_sb_buildstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
