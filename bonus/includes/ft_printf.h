/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:51:46 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/15 18:32:37 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_string_builder.h"

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

int			ft_printf(const char *s, ...);
int			ft_parseformat(t_conv *out, char *format);

int			ft_pfbuildchar(t_sbuild *out, t_conv *conv, char c);
int			ft_pfbuildstr(t_sbuild *out, t_conv *conv, char *str);
int			ft_pfbuildnb(t_sbuild *out, t_conv *conv, int nb);
int			ft_pfbuildunsnb(t_sbuild *out, t_conv *conv, t_uint32 nb);
int			ft_pfbuildhexa(t_sbuild *out, t_conv *conv, t_uint32 nb);
int			ft_pfbuildptr(t_sbuild *out, t_conv *conv, t_uint64 nb);
int			ft_pfnullcheck(t_sbuild *out, t_conv *conv, t_uint64 value, char *error);

char		*ft_strprcut(char *str, int precision);
int			ft_digitcount(int nb);
char		ft_getsign(int nb);
int			ft_unslngdigitcount(t_uint64 nb);
char		*ft_unslngitoa(t_uint64 nb);
t_uint64	ft_unslngatoi_base(char *str, char *base);
int			ft_unslngdigitcount_base(t_uint64 dec, char *base_to);
char		*ft_unslngconvert_base(char *n, char *base_from, char *base_to);

#endif
