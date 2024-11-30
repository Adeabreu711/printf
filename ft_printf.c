/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:45 by alde-abre         #+#    #+#             */
/*   Updated: 2024/11/30 17:19:24 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	ft_printf(char *s, ...)
{
	va_list ptr;
	va_start(ptr, s);
}

int	main()
{
	ft_printf("test", 10, 40, 65);
	//printf("test %   i, %c\n",42, 42, 42);
}