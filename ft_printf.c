/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:45 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/09 19:28:12 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_applyformat(char c, va_list ptr)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ptr, int)));
	else if (c == 'u')
		return (ft_putunsnbr(va_arg(ptr, int)));
	else if (c == 'x' || c == 'X')
		return (ft_displayhexa(va_arg(ptr, unsigned int), c));
	if (c == 'p')
		return (ft_displayptr(va_arg(ptr, unsigned long)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	char	c;
	va_list	ptr;

	va_start(ptr, s);
	i = -1;
	count = 0;
	while (s[++i])
	{
		c = ft_getformat(s + i++, "cspdiuxX%");
		if (!c)
			count += ft_putchar(s[--i]);
		else
			count += ft_applyformat(c, ptr);
	}
	return (count);
}

// int	main(int argc, char *argv[])
// {
// 	(void)argc;
// 	(void)argv;
// 	char *t = "test";
// 	// ft_printf("ft_test : %c\n", 0xFFF);
// 	// printf("test    : %c\n", 0xFFF);

// 	TEST("TEST %p\n", 0x7FFFFFFFFFFFFFFF);

// 	// printf("%i\n", ft_printf("ft_test : %p\n", t));
// 	// printf("%i\n", printf("test    : %p\n", t));
// }
