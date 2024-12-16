/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_builder.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:28:08 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/16 19:01:24 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_BUILDER_H
# define FT_STRING_BUILDER_H

# define SB_SIZE 10

# include "libft.h"
# include "stdio.h"

typedef struct s_sbuild
{
	char	str[SB_SIZE];
	void	*next;
}	t_sbuild;

//utils :
t_sbuild	*ft_sbnew(char *str);
void		ft_sbclear(t_sbuild **container);
t_sbuild	*ft_sblast(t_sbuild *container);
int			ft_sblen(t_sbuild *container);

//string builder :
void		*ft_sb_buildstr(t_sbuild **container, char *str, size_t n);
int			ft_sb_display(t_sbuild *container);

#endif
