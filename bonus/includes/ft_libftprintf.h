/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:53:39 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/09 17:56:30 by alde-abr         ###   ########.fr       */
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
int		ft_pfbuildhexa(t_sbuild *out, t_conv *conv, unsigned int nb);

char	*ft_strprcut(char *str, int precision);
int		ft_digitcount(int nb);
char	ft_getsign(int nb);

int		ft_unslngdigitcount(unsigned long nb);
char	*ft_unslngitoa(unsigned long nb);
int		ft_unslngatoi_base(char *str, char *base);
int		ft_unslngdigitcount_base(unsigned long dec, char *base_to);
char	*ft_unslngconvert_base(char *n, char *base_from, char *base_to);

#endif
