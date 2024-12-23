/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_builder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:27:55 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/23 19:05:56 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_builder.h"
#include "libft.h"

/**
 * @brief the given last->next become the new given ptr, sb_len become 0.
 * @return last->next.
 */
t_sbuild	*ft_sbnext(t_sbuild *last, t_sbuild *new, int *sb_len)
{
	last->next = new;
	*sb_len = 0;
	return (new);
}

/**
 * @brief Add n char of the given str at the end of the last sb (string builder) string.
 */
void	*ft_sb_buildstr(t_sbuild **container, char *str, size_t n)
{
	t_sbuild	*last;
	size_t		i;
	int			sb_len;

	i = 0;
	last = ft_sblast(*container);
	if (!*container || !last || SB_SIZE <= 1)
		return (*container);
	while (str[i])
	{
		sb_len = ft_strlen(last->str);
		if ((SB_SIZE - 1) - sb_len <= 0)
			last = ft_sbnext(last, ft_sbnew(""), &sb_len);
		if ((int)(n - i) > (SB_SIZE - 1) - sb_len)
			ft_memmove(last->str + sb_len, str + i, (SB_SIZE - 1) - sb_len);
		else
		{
			ft_memmove(last->str + sb_len, str + i, n - i);
			break ;
		}

		i += (SB_SIZE - 1) - sb_len;
	}
	return (*container);
}

/**
 * @brief Display all of the given sb (string builder) container strings.
 * @return The lenght of the total amount of char in the given sb.
 */
int	ft_sb_display(t_sbuild *container)
{
	t_sbuild	*temp;

	temp = container;
	ft_putchar('[');
	while (temp->next)
	{
		ft_putstr(temp->str);
		temp = temp->next;
	}
	ft_putstr(temp->str);
	ft_putchar(']');
	return (ft_sblen(container));
}
