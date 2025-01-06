/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildhexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:01:33 by alex              #+#    #+#             */
/*   Updated: 2025/01/06 21:31:55 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_pfbuildhexa(t_sbuild *out, t_conv *conv, unsigned int nb)
{
	char	*temp;
	int		size;

	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);

	ft_sb_buildstr(&out, temp, size);
	free(temp);
}
