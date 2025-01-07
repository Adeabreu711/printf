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

void	ft_assign_unslngnb(char *temp, t_conv *conv, unsigned long nb, int size)
{
	int	nblen;

	nblen = ft_unslngdigitcount(nb);
	if (!!(conv->flags & ALIGN_L))
		ft_memmove(temp, ft_unslngitoa(nb), nblen);
	else
		ft_memmove(temp + (size - nblen), ft_unslngitoa(nb), nblen);
}

int	ft_pfbuildunsnb(t_sbuild *out, t_conv *conv, unsigned int nb)
{
	char	*temp;
	int		size;

	size = ft_unslngdigitcount((unsigned long)nb);
	if (conv->witdh > size)
		size = conv->witdh;
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	if (!(conv->flags & ALIGN_L))
		temp = ft_memset(temp, '0', size);
	else
		temp = ft_memset(temp, ' ', size);
	ft_assign_unslngnb(temp, conv, (unsigned long)nb, size);
	ft_sb_buildstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
