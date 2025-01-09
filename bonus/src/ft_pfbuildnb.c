/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildnb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:54:25 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/09 19:53:19 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

char	ft_getsign(int nb)
{
	if (nb < 0)
		return ('-');
	return ('+');
}

static char	*ft_set_tempunsnb(char *temp, t_conv *conv, int size, int nblen)
{
	int	i;

	i = 0;
	temp = ft_memset(temp, ' ', size);
	if (nblen < conv->precision)
	{
		nblen = conv->precision;
		i = (size - nblen) * !(conv->flags & ALIGN_L);
		i += !!(conv->flags & ALIGN_L) * !!(conv->flags & ADD_SPACE);
		while (--nblen >= 0)
			temp[i++] = '0';
	}
	else if ((conv->flags & NFILL) && conv->precision == -1)
		temp = ft_memset(temp, '0', size);

	return (temp);
}

void	ft_assign_nb(char *temp, t_conv *conv, int nb, int size)
{
	int	nblen;
	int	offset;

	offset = !!(conv->flags & ADD_SPACE);
	nblen = ft_digitcount(nb);
	if (nblen < conv->precision)
		offset += conv->precision - nblen;
	if (!!(conv->flags & ALIGN_L))
		ft_memmove(temp + !!(conv->flags & SIGN) + offset, ft_itoa(nb), nblen);
	else
		ft_memmove(temp + (size - nblen), ft_itoa(nb), nblen);
	if ((!!(conv->flags & NFILL) && conv->precision == -1)
		|| !!(conv->flags & ALIGN_L))
		temp[0] += (ft_getsign(nb) - temp[0]) * !!(conv->flags & SIGN);
	else
		temp[size - nblen - 1] += (ft_getsign(nb) - temp[size - nblen - 1])
			* !!(conv->flags & SIGN);
}

int	ft_pfbuildnb(t_sbuild *out, t_conv *conv, int nb)
{
	char	*temp;
	int		size;
	int		sflag;

	size = ft_digitcount(nb) + sflag;
	sflag = ((conv->flags & SIGN) || (conv->flags & ADD_SPACE));
	if (conv->witdh > size || conv->witdh > size)
	{
		size = ft_intcomp(conv->witdh, conv->precision, 1);
		size += !conv->witdh * sflag;
	}
	//printf("size : %i", size);
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	temp = ft_set_tempunsnb(temp, conv, size, ft_digitcount(nb));
	ft_assign_nb(temp, conv, nb, size);
	ft_sb_buildstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
