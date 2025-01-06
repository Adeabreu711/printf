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

void	ft_assign_unsnb(char *temp, t_conv *conv, unsigned int nb, int size)
{
	int	nblen;
	
	nblen = ft_unsdigitcount(nb);
	if (!!(conv->flags & ALIGN_L))
		ft_memmove(temp, ft_itoa(nb), nblen);
	else
		ft_memmove(temp + (size - nblen), ft_itoa(nb), nblen);
}

int	ft_pfbuildunsnb(t_sbuild *out, t_conv *conv, unsigned int nb)
{
	char	*temp;
	int		size;

	size = ft_unsdigitcount(nb);
	if (conv->witdh > size)
		size = conv->witdh;
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	if (!(conv->flags & ALIGN_L))
		temp = ft_memset(temp, '0', size);
	else
		temp = ft_memset(temp, ' ', size);
	ft_assign_unsnb(temp, conv, nb, size);
	ft_sb_buildstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
