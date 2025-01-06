/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:37:51 by alex              #+#    #+#             */
/*   Updated: 2025/01/06 19:00:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"
#include "libft.h"

char	*ft_unsbase(unsigned long n, char *base)
{
	
}

char	*ft_unsitoa_base(unsigned long n, char *base)
{
	printf("itoa : %u", ft_base_to_decimal(n, ft_strlen(base), base));
}
