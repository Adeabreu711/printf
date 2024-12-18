/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:29:05 by alde-abr          #+#    #+#             */
/*   Updated: 2024/11/22 15:52:12 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Erase the first "n" bytes of the memory area pointed to.
 * @param {void*} "s" pointer to the targeted memory location.
 * @param {size_t} "n" size.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
