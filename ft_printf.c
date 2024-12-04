/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:45 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/04 18:44:34 by alde-abre        ###   ########.fr       */
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
			ft_putchar(va_arg(ptr, int));
		else if (c == 's')
			ft_putstr(va_arg(ptr, char *));
		else if (c == 'd' || c == 'i' || c == 'u')
			ft_displaynumbers(va_arg(ptr, long), c);
		else if (c == 'x' || c == 'X' || c == 'p')
			ft_displayhexa(va_arg(ptr, unsigned int), c);
		else if (c == '%')
			ft_putchar('%');
	}
}

// int	main(int argc, char *argv[])
// {
// 	char	*test;

// 	(void)argc;
// 	(void)argv;
// 	test = "test";
// 	ft_printf("ft_test : %c\n", 0xFFF);
// 	printf("test    : %c\n", 0xFFF);
// }
