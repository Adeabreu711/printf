/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:13:46 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/04 17:43:38 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

void	ft_printf(char *s, ...);
char	ft_getformat(char *s, char *set);
void	ft_displaynumbers(long value, char form);
void	ft_displayhexa(long value, char form);

#endif
