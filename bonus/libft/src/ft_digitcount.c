/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:50:03 by alex              #+#    #+#             */
/*   Updated: 2025/01/06 16:52:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @return The number of digits in the the given int "n".
 */
int	ft_digitcount(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}
