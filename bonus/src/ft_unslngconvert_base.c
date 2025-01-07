/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unslngconvert_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:37:51 by alex              #+#    #+#             */
/*   Updated: 2025/01/07 23:44:26 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"
#include "libft.h"

/**
 * @brief Add to the given char * "s" the result of the
 * decimal to base convertion.
 */
static void	ft_strnbr_to_base(unsigned long dec, char *base, char *s)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (dec > base_len - 1)
	{
		ft_strnbr_to_base(dec / base_len, base, s);
		ft_strnbr_to_base(dec % base_len, base, s);
	}
	else
		ft_memmove(s + ft_strlen(s), base + dec, 1);
}

/**
 * @return The number of digits in the give int "dec" (decimal)
 * converted into the given base "base_to" .
 */
int	ft_unslngdigitcount_base(unsigned long dec, char *base_to)
{
	int	count;
	unsigned long	temp;
	int	base_len;

	base_len = ft_strlen(base_to);
	temp = 1;
	count = 0;
	while (temp <= dec)
	{
		temp *= base_len;
		count++;
	}
	return (count);
}

/**
 * @brief Converts the given string "n" into another base.
 *
 * @param n Pointer to the string representing the value to convert.
 * @param base_from Pointer to the string representing the base of the input value "n".
 * @param base_to Pointer to the string representing the desired target base.
 * @return A pointer to the converted string "n" in the given target base "base_to".
 */
char	*ft_unslngconvert_base(char *n, char *base_from, char *base_to)
{
	char			*s;
	unsigned long	dec;

	dec = ft_atoi_base(n, base_from);
	s = ft_calloc(ft_unslngdigitcount_base(dec, base_to) + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_strnbr_to_base(dec, base_to, s);
	return (s);
}