/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:09:46 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/30 16:21:06 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_checknullstr(t_sbuild *out, char *str, int prc)
{
	if (!str && prc == -1)
	{
		ft_sb_buildstr(&out, "(null)", 6);
		return (0);
	}
	else if (!str)
		return(0);
	return (1);
}

int	ft_pfbuildstr(t_sbuild *out, t_conv *conv, char *str)
{
	char	*temp;
	int		size;
	int		slen;

	if (!ft_checknullstr(out, str, conv->precision))
		return (conv->lenght);
	slen = ft_strlen(str);
	if (conv->precision >= 0 && conv->precision < slen)
		slen = conv->precision;
	size = slen;
	if (conv->witdh > slen)
		size = conv->witdh;
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	temp = ft_memset(temp, ' ', size);
	if (!!(conv->flags & ALIGN_L))
		ft_memmove(temp, str, slen);
	else
		ft_memmove(temp + (size - slen), str, slen);
	ft_sb_buildstr(&out, temp, size);
	return (conv->lenght);
}
