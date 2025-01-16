/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:11:24 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/16 15:12:37 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strdigitcount(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (ft_isdigit(str[++i]))
		count++;
	return (count);

}

void	ft_init_conv(t_conv *out)
{
	ft_memset(out, 0, sizeof(t_conv));
	out->precision = -1;
	out->flags = 0;
}

void	ft_get_flags(t_conv *out, char *format)
{
	int				i;
	int				temp;
	unsigned char	bit;

	i = -1;
	bit = 0b10000000;
	while (format[++i] && ft_strchr("-+0 #", format[i]))
	{
		temp = ft_strlen(ft_strchr("-+0 #", format[i]));
		if (temp)
			out->flags |= bit >> (5 - temp);
	}
	out->lenght += i;
}

int	ft_parseformat(t_conv *out, char *format)
{
	if (format[0] != '%')
		return (0);
	ft_init_conv(out);
	out->lenght++;
	ft_get_flags(out, format + out->lenght);
	out->witdh = ft_atoi(format + out->lenght);
	if (ft_isdigit(format[out->lenght]))
		out->lenght += ft_strdigitcount(format + out->lenght);
	if (!format[out->lenght])
		return (0);
	if (format[out->lenght] == '.')
	{
		out->precision = ft_atoi(format + (out->lenght + 1));
		if (ft_isdigit(format[out->lenght + 1]))
			out->lenght += ft_strdigitcount(format + out->lenght + 1);
		out->lenght++;
	}
	if (ft_strchr("cspdiuxX%", format[out->lenght]))
		out->type = *ft_strchr("cspdiuxX%", format[out->lenght]);
	if (out->type)
	{
		//printf("witdh : %i, precision : %i, type : %c\n", out->witdh, out->precision, out->type);
		out->lenght++;
		return (out->lenght);
	}
	return (0);
}

// char c = 0b10000000;

// 0b10100000 & 0b10001000 = 0b10000000; c = (c & 0b10001000); c &= 0b10001000
// 0b10000000 | 0b10001111 = 0b10001111;
// ~c = 0b0111111
// 0b00100000 ^ 0b10001000 = 10
// 0b00101001 >> 2 = 00001010

// & : 00110(4) & 00101(5) = 000100 (4)
// &= : 00110 &= 00101 (00100) var 1 = (var1 & var2)
// | : 00010(4) | 011101(29) = 011111 (31)
// |= :
// ~(var) : ~010101 = 101010
// ^ : 011010 ^ 101010 = 110000
// 011010 << 2 => 101000
// >>

//"# 0-+"
// 0 -> 2
// 0b001 << 2
// 0b100
