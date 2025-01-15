/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfnullcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:10:04 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/15 22:03:23 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_pfnullcheck(t_sbuild *out, t_conv *conv, t_uint64 is_null, char *error)
{
	int	fill_size;
	int	err_len;

	fill_size = 0;
	err_len = ft_strlen(error);
	if (is_null && ((!conv->precision) || err_len > 0))
	{
		if (conv->witdh > err_len)
			fill_size = conv->witdh - err_len;
		if (conv->flags & ALIGN_L)
		{
			ft_sb_buildstr(&out, error, err_len);
			while (fill_size-- > 0)
				ft_sb_buildstr(&out, " ", 1);
			return (0);
		}
		while (fill_size-- > 0)
				ft_sb_buildstr(&out, " ", 1);
		ft_sb_buildstr(&out, error, err_len);
		return (0);
	}
	return (1);
}

