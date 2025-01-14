/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:07:19 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/13 18:39:52 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_pfbuildchar(t_sbuild *out, t_conv *conv, char c)
{
	char	*temp;
	int		size;

	if (!c)
	{
		ft_sb_buildstr(&out, "\0", 1);
		return (conv->lenght);
	}
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
//% flag"+ #0-" 0-9. 0-9 type ""

//% 0+9.3i 78 "00000078"
