/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:45 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/03 17:56:09 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void	ft_printf(char *s, ...)
{
	int		i;
	char	c;
	va_list	ptr;

	va_start(ptr, s);
	i = -1;
	while (s[++i])
	{
		c = ft_getformat(s + i++, "cspdiuxX%");
		if (!c)
			ft_putchar(s[--i]);
		else if (c == 'c')
			ft_putchar(*va_arg(ptr, char *));
		else if (c == 's')
			ft_putstr(va_arg(ptr, char *));
		else if (c == 'p')
			ft_putstr(va_arg(ptr, void *));
		else if (c == 'd' || c == 'i' || c == 'u')
			ft_putchar(va_arg(ptr, int));
		else if (c == 'x' || c == 'X')
			ft_putchar(va_arg(ptr, int));
		else if (c == '%')
			ft_putchar(va_arg(ptr, int));
	}
}
//printf("s[%i] : %c\n", i, s[i]);
//printf("format : %c\n", c);

int	main()
{
	char *test = "test";
	ft_printf("ft_test : %p\n", test);
	printf("test : %d\n", -9223372036854775807.7);
}