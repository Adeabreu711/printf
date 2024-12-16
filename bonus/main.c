/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:06 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/16 20:01:13 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"
#include "libft.h"
#include "ft_string_builder.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_sbuild	*sb;
	t_sbuild	*temp;

	sb = ft_sbnew("");
	char	c = 'a';
	ft_sb_buildstr(&sb, "0123456789", 10);

	temp = sb;
	while (temp->next)
	{
		printf("str : [%s] next : (%p)\n", temp->str, temp->next);
		temp = temp->next;
	}
	printf("str : [%s] next : (%p)\n", temp->str, temp->next);
	printf("len : %i\n", ft_sblen(sb));

	ft_sb_display(sb);
	printf("\ndone\n");
}
