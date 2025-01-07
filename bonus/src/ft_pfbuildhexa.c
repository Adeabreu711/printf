/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildhexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:01:33 by alex              #+#    #+#             */
/*   Updated: 2025/01/07 23:50:50 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

char	*ft_getbase(char type)
{
	if (type = 'x')
		return("0123456789abcdef");
	return("0123456789ABCDEF");
}

int	ft_pfbuildhexa(t_sbuild *out, t_conv *conv, unsigned int nb)
{
	char	*temp;
	char	*base;
	int		size;

	base = ft_getbase(conv->type);
	size = ft_unslngdigitcount_base((unsigned long)nb, base);
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);

	ft_sb_buildstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
