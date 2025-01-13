/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildhexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:01:33 by alex              #+#    #+#             */
/*   Updated: 2025/01/13 14:36:23 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_get_ptr_size(t_conv *conv, int hexalen)
{
	int	size;
	int	sflag;

	size = hexalen;
	sflag = conv->precision + !!(conv->flags & PREFIX) * 2;
	if (conv->precision > hexalen && conv->witdh < sflag)
		return (sflag);
	else if (conv->witdh > size || conv->precision > size)
		size = ft_intcomp(conv->witdh, conv->precision, 1);
	if (!!(conv->flags & PREFIX) && conv->witdh < hexalen + 2
		&& conv->witdh > conv->precision)
		size += 2;
	return (size);
}

static char	*ft_set_tempunsnb(char *temp, t_conv *conv, int size, int hexalen)
{
	int	i;

	i = 0;
	temp = ft_memset(temp, ' ', size);
	if (hexalen < conv->precision)
	{
		hexalen = conv->precision;
		i = (size - hexalen) * !(conv->flags & ALIGN_L);
		while (--hexalen >= 0)
			temp[i++] = '0';
	}
	else if ((conv->flags & NFILL) && !(conv->flags & ALIGN_L)
		&& conv->precision == -1)
		temp = ft_memset(temp, '0', size);
	return (temp);
}

static char	*ft_assign_hexa(char *temp, t_conv *conv, t_uint32 nb, char *base)
{
	char	*hexa;
	char	*dec;
	int		hexalen;
	int		size;
	int		offset;

	size = strlen(temp);
	dec = ft_unslngitoa((t_uint64)nb);
	hexa = ft_unslngconvert_base(dec, "0123456789", base);
	hexalen = ft_strlen(hexa);
	offset = (conv->precision - hexalen) * (hexalen < conv->precision);
	if (!!(conv->flags & ALIGN_L))
	{
		if ((conv->flags & PREFIX))
			ft_memmove(temp, "0x", 2);
		ft_memmove(temp + !!(conv->flags & PREFIX) * 2 + offset, hexa, hexalen);
		return (free(hexa), free(dec), temp);
	}
	if ((conv->flags & NFILL) && conv->precision == -1 && conv->flags & PREFIX)
		ft_memmove(temp, "0x", 2);
	else if (conv->flags & PREFIX)
		ft_memmove(temp + (size - hexalen - offset) - 2, "0x", 2);
	ft_memmove(temp + (size - hexalen), hexa, hexalen);
	return (free(hexa), free(dec), temp);
}

int	ft_pfbuildhexa(t_sbuild *out, t_conv *conv, t_uint32 nb)
{
	char	*temp;
	char	*base;
	int		hexalen;
	int		size;

	base = "0123456789abcdef";
	hexalen = ft_unslngdigitcount_base((t_uint64)nb, base);
	size = ft_get_ptr_size(conv, hexalen);
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	temp = ft_set_tempunsnb(temp, conv, size, hexalen);
	temp = ft_assign_hexa(temp, conv, nb, base);
	if (conv->type == 'X')
		temp = ft_strupcase(temp);
	ft_sb_buildstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
