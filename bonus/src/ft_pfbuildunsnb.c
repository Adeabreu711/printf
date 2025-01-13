/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildunsnb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:43:21 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/13 12:54:55 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_set_tempunsnb(char *temp, t_conv *conv, int size, int nblen)
{
	int	i;

	i = 0;
	temp = ft_memset(temp, ' ', size);
	if (nblen < conv->precision)
	{
		nblen = conv->precision;
		i = (size - nblen) * !(conv->flags & ALIGN_L);
		while (--nblen >= 0)
			temp[i++] = '0';
	}
	else if ((conv->flags & NFILL) && conv->precision == -1)
		temp = ft_memset(temp, '0', size);
	return (temp);
}

static char	*ft_assign_unslngnb(char *temp, t_conv *conv, t_uint64 nb, int size)
{
	int		nblen;
	int		offset;
	char	*snb;

	nblen = ft_unslngdigitcount(nb);
	offset = (conv->precision - nblen) * (nblen < conv->precision);
	snb = ft_unslngitoa(nb);
	if (!!(conv->flags & ALIGN_L))
		ft_memmove(temp + offset, snb, nblen);
	else
		ft_memmove(temp + (size - nblen), snb, nblen);
	return (free(snb), temp);
}

int	ft_pfbuildunsnb(t_sbuild *out, t_conv *conv, t_uint32 nb)
{
	char	*temp;
	int		size;

	size = ft_unslngdigitcount((t_uint64)nb);
	if (conv->witdh > size || conv->precision > size)
		size = ft_intcomp(conv->witdh, conv->precision, 1);
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	temp = ft_set_tempunsnb(temp, conv, size, ft_digitcount(nb));
	ft_assign_unslngnb(temp, conv, (t_uint64)nb, size);
	ft_sb_buildstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
