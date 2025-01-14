/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_builder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:27:55 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/13 17:59:08 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string_builder.h"
#include "../includes/libft.h"

/**
 * @brief the given last->next become the new given ptr, sb_len become 0.
 * @return last->next.
 */
t_sbuild	*ft_sbnext(t_sbuild *last, t_sbuild *new)
{
	last->next = new;
	last->id = SB_SIZE - 1;
	return (new);
}

/**
 * @brief Add n char of the given str at the end of
 * the last sb (string builder) string.
 */
void	*ft_sb_buildstr(t_sbuild **container, char *str, size_t n)
{
	t_sbuild	*last;
	size_t		i;

	i = 0;
	last = ft_sblast(*container);
	if (!*container || !last || SB_SIZE <= 1)
		return (*container);
	while (i < n)
	{
		if ((SB_SIZE - 1) - last->id <= 0)
			last = ft_sbnext(last, ft_sbnew(""));
		if ((int)(n - i) > (SB_SIZE - 1) - last->id)
		{
			ft_memmove(last->str + last->id, str + i, (SB_SIZE - 1) - last->id);
			i += (SB_SIZE - 1) - last->id;
			last->id = SB_SIZE - 1;
		}
		else
		{
			ft_memmove(last->str + last->id, str + i, n - i);
			last->id += n - i;
			break ;
		}
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
	while (temp->next)
	{
		ft_putstrn(temp->str, temp->id);
		// printf("temp : (%s)\n", temp->str);
		// printf("id size : %i\n", temp->id);
		temp = temp->next;
	}
	ft_putstrn(temp->str, temp->id);
	// printf("id size : %i\n", temp->id);
	return (ft_sblen(container));
}
