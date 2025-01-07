/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:45 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/07 20:38:09 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_pfgetformat(t_sbuild *sb, int count, char *s)
{
	ft_sb_buildstr(&sb, (char *)s + count, 1);
	return (1);
}

int	ft_applyconv(va_list ptr, t_conv *conv, t_sbuild *sb)
{
	if (conv->type == 'c')
		return (ft_pfbuildchar(sb, conv, va_arg(ptr, int)));
	else if (conv->type == 's')
		return (ft_pfbuildstr(sb, conv, va_arg(ptr, char *)));
	else if (conv->type == 'i' || conv->type == 'd')
		return (ft_pfbuildnb(sb, conv, va_arg(ptr, int)));
	else if (conv->type == 'u')
		return (ft_pfbuildunsnb(sb, conv, va_arg(ptr, unsigned int)));
	else if (conv->type == 'x' || conv->type == 'X')
		return (ft_pfbuildhexa(sb, conv, va_arg(ptr, unsigned int)));
	ft_sb_buildstr(&sb, "%", 1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int			count;
	va_list		ptr;
	t_conv		conv;
	t_sbuild	*sb;

	sb = ft_sbnew("");
	va_start(ptr, s);
	count = 0;
	while (s[count])
	{
		if (!ft_parseformat(&conv, (char *)s + count))
			count += ft_pfgetformat(sb, count, (char *)s);
		else
			count += ft_applyconv(ptr, &conv, sb);
	}
	count = ft_sb_display(sb);
	ft_sbclear(&sb);
	va_end(ptr);
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
#

%10c, 'A' "         A"

%.4d, 45 "0045"
%04d, 45 "0045"
%8.4, 45 "    0045"
%-8d, 1000 "1000    "
%+4.2d, 5 " +05"
%#5.2x, 5 " 0x05"

*/
