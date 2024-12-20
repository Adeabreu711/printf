/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:53:39 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/20 13:04:17 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "libft.h"
# include "ft_string_builder.h"

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define ALIGN_L	0b10000 // '-'
# define SIGN		0b01000 // '+'
# define NFILL		0b00100 // '0'
# define ADD_SPACE	0b00010 // ' '
# define PREFIX		0b00001 // '#'

typedef struct s_conv
{
	char	flags;
	int		witdh;
	int		precision;
	char	type;
	int		lenght;
}	t_conv;

int		ft_printf(const char *s, ...);
char	ft_gettype(const char *s, char *set);
int		ft_putcharlen(char c);
int		ft_putstrlen(char *s);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putnbr(int n);
int		ft_putunsnbr(unsigned int n);
int		ft_displayhexa(unsigned int value, char form);
int		ft_displayptr(unsigned long value);

int	ft_parseformat(t_conv *out, char *format);
void ft_displaychar(t_sbuild *out, t_conv *conv, char c);

#endif
