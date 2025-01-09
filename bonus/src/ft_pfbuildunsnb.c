/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildunsnb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:54:25 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/04 20:15:44 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

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

void	ft_assign_unslngnb(char *temp, t_conv *conv, unsigned long nb, int size)
{
	int	nblen;
	int	offset;

	nblen = ft_unslngdigitcount(nb);
	offset = (conv->precision - nblen) * (nblen < conv->precision);
	if (!!(conv->flags & ALIGN_L))
		ft_memmove(temp + offset, ft_unslngitoa(nb), nblen);
	else
		ft_memmove(temp + (size - nblen), ft_unslngitoa(nb), nblen);
}

int	ft_pfbuildunsnb(t_sbuild *out, t_conv *conv, uint32 nb)
{
	char	*temp;
	int		size;

	size = ft_unslngdigitcount((uint64)nb);
	if (conv->witdh > size || conv->precision > size)
		size = ft_intcomp(conv->witdh, conv->precision, 1);
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	if (!!(conv->flags & NFILL) && !(conv->flags & ALIGN_L)
		&& conv->precision == -1)
		temp = ft_memset(temp, '0', size);
	else
		temp = ft_memset(temp, ' ', size);
	temp = ft_set_tempunsnb(temp, conv, size, ft_digitcount(nb));
	ft_assign_unslngnb(temp, conv, (uint64)nb, size);
	ft_sb_buildstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
