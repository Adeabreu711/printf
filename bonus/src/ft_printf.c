/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:45 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/16 18:15:38 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_applyformat(char c, va_list ptr)
{
	if (c == 'c')
		return (ft_putcharlen(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_putstrlen(va_arg(ptr, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ptr, int)));
	else if (c == 'u')
		return (ft_putunsnbr(va_arg(ptr, int)));
	else if (c == 'x' || c == 'X')
		return (ft_displayhexa(va_arg(ptr, unsigned int), c));
	if (c == 'p')
		return (ft_displayptr(va_arg(ptr, unsigned long)));
	else if (c == '%')
		return (ft_putcharlen('%'));
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
		c = ft_gettype(s + i++, "cspdiuxX%");
		if (!c)
			count += ft_putcharlen(s[--i]);
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

/*

%l45.6d

%[+- #0]*[0-9]*        .[0-9]*     [cspdiuxX%]
 Flags   Field_width   Precision   Conversion specifier

+ di
- *
0 diuxX
' ' di
# xX


%10c, 'A' "         A"

%.4d, 45 "0045"
%04d, 45 "0045"
%8.4, 45 "    0045"
%-8d, 1000 "1000    "
%+4.2d, 5 " +05"
%#5.2x, 5 " 0x05"

*/