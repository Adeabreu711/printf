/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:13:46 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/23 12:35:34 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
char	ft_gettype(const char *s, char *set);
int		ft_pfstrlen(char *str);
int		ft_pfputchar(char c);
int		ft_pfputstr(char *s);
int		ft_pfputnbr(int n);
int		ft_pfputunsnbr(unsigned int n);
int		ft_displayhexa(unsigned int value, char form);
int		ft_displayptr(unsigned long value);

#endif
