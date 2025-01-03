/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:20:45 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/30 17:10:58 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_pfgetformat(t_sbuild *sb, t_conv *conv, int count, char *s)
{
	ft_sb_buildstr(&sb, (char *)s + count, 1);
	return (1);
}

int	ft_applyconv(va_list ptr, t_conv *conv, t_sbuild *sb)
{
	//printf ("type : %c\n", conv->type);
	if (conv->type == 'c')
		return (ft_pfbuildchar(sb, conv, va_arg(ptr, int)));
	else if (conv->type == 's')
		return (ft_pfbuildstr(sb, conv, va_arg(ptr, char *)));
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
			count += ft_pfgetformat(sb, &conv, count, (char *)s);
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
