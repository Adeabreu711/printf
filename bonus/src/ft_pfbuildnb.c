/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildnb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:54:25 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/06 17:56:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

char	ft_getsign(int nb)
{
	if (nb < 0)
		return ('-');
	return ('+');
}

void	ft_assign_nb(char *temp, t_conv *conv, int nb, int size)
{
	int	nblen;
	
	nblen = ft_digitcount(nb);
	if (!!(conv->flags & ALIGN_L))
	{
		ft_memmove(temp + !!(conv->flags & SIGN), ft_itoa(nb), nblen);
		temp[0] += (ft_getsign(nb) - temp[0]) * !!(conv->flags & SIGN);
		return ;
	}
	ft_memmove(temp + (size - nblen), ft_itoa(nb), nblen);
	temp[size - nblen - 1] += (ft_getsign(nb) - temp[size - nblen - 1]) * !!(conv->flags & SIGN);
}

int	ft_pfbuildnb(t_sbuild *out, t_conv *conv, int nb)
{
	char	*temp;
	int		size;

	size = ft_digitcount(nb) + !!(conv->flags & SIGN);
	if (conv->witdh > size)
		size = conv->witdh;
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	if (!!(conv->flags & NFILL) && !(conv->flags & ALIGN_L))
		temp = ft_memset(temp, '0', size);
	else
		temp = ft_memset(temp, ' ', size);
	ft_assign_nb(temp, conv, nb, size);
	ft_sb_buildstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
