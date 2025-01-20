/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:13:46 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/11 13:34:21 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
char	ft_gettype(const char *s, char *set);
int		ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunsnbr(unsigned int n);
int		ft_displayhexa(unsigned int value, char form);
int		ft_displayptr(unsigned long value);

#endif
