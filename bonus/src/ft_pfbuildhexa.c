/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildhexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:01:33 by alex              #+#    #+#             */
/*   Updated: 2025/01/09 20:14:40 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void	ft_assign_hexa(char *temp, t_conv *conv, uint32 nb, char *base)
{
	char	*hexa;
	int		hexa_len;
	int		size;
	char	*dec_base;

	dec_base = "0123456789";
	size = strlen(temp);
	printf("size : %i\n", size);
	hexa = ft_unslngconvert_base(ft_unslngitoa((uint64)nb), dec_base, base);
	hexa_len = ft_strlen(hexa);
	printf("hexa : %s\n", hexa);
	if (!!(conv->flags & ALIGN_L))
	{
		if (!!(conv->flags & PREFIX))
			ft_memmove(temp, "0x", 2);
		ft_memmove(temp + !!(conv->flags & PREFIX) * 2, hexa, hexa_len);
		return ;
	}
	ft_memmove(temp + (size - hexa_len) - 2, "0x", 2);
	ft_memmove(temp + (size - hexa_len), hexa, hexa_len);

}

int	ft_pfbuildhexa(t_sbuild *out, t_conv *conv, uint32 nb)
{
	char	*temp;
	char	*base;
	int		size;

	base = "0123456789abcdef";
	//printf("temp : %s\n", temp);
	size = ft_unslngdigitcount_base((uint64)nb, base);
	if (conv->witdh > size)
		size = conv->witdh;
	else if (!!(conv->flags & PREFIX))
		size += 2;
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	if (!!(conv->flags & NFILL) && !(conv->flags & ALIGN_L))
		ft_memset(temp, '0', size);
	else
		ft_memset(temp, ' ', size);
	ft_assign_hexa(temp, conv, nb, base);
	if (conv->type == 'X')
		temp = ft_strupcase(temp);
	ft_sb_buildstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
