/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfnullcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:10:04 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/15 19:10:41 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_pfnullcheck(t_sbuild *out, t_conv *conv, t_uint64 is_null, char *error)
{
	int	fill_size;

	fill_size = 0;
	if (is_null && !conv->precision)
	{
		if (conv->witdh > ft_strlen(error))
			fill_size = conv->witdh - ft_strlen(error);
		if (conv->flags & ALIGN_L)
		{
			ft_sb_buildstr(&out, error, ft_strlen(error));
			while (fill_size-- > 0)
				ft_sb_buildstr(&out, " ", 1);
			return (0);
		}
		while (fill_size-- > 0)
				ft_sb_buildstr(&out, " ", 1);
		ft_sb_buildstr(&out, error, ft_strlen(error));
		return (0);
	}
	return (1);
}
