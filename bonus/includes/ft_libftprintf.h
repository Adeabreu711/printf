/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:53:39 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/06 18:50:42 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include "libft.h"
# include "ft_string_builder.h"

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define ALIGN_L	0b10000000 // '-'
# define SIGN		0b01000000 // '+'
# define NFILL		0b00100000 // '0'
# define ADD_SPACE	0b00010000 // ' '
# define PREFIX		0b00001000 // '#'

typedef struct s_conv
{
	char	flags;
	int		witdh;
	int		precision;
	char	type;
	int		lenght;
}	t_conv;

int		ft_printf(const char *s, ...);
int		ft_putstrlen(char *s);
int		ft_putnbr_base(int nbr, char *base);
int		ft_displayhexa(unsigned int value, char form);
int		ft_displayptr(unsigned long value);

int		ft_parseformat(t_conv *out, char *format);
int		ft_pfbuildchar(t_sbuild *out, t_conv *conv, char c);
int		ft_pfbuildstr(t_sbuild *out, t_conv *conv, char *str);
int		ft_pfbuildnb(t_sbuild *out, t_conv *conv, int nb);
int		ft_pfbuildunsnb(t_sbuild *out, t_conv *conv, unsigned int nb);

char	*ft_strprcut(char *str, int precision);
int		ft_digitcount(int nb);
char	ft_getsign(int nb);

int		ft_unsdigitcount(unsigned int nb);
char	*ft_unsitoa(unsigned int nb);
char	*ft_unsitoa_base(unsigned long n, char *base);

#endif
