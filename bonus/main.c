/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:06 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/17 17:19:09 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"
#include "libft.h"
#include "ft_string_builder.h"

void	ft_debugconv(t_conv *conv)
{
	ft_putstr("flags : ");
	ft_putbits(conv->flags);
	ft_putchar('\n');
	ft_putstr("widht : ");
	ft_putnbr(conv->witdh);
	ft_putchar('\n');
	ft_putstr("precision : ");
	ft_putnbr(conv->precision);
	ft_putchar('\n');
	ft_putstr("type : ");
	ft_putchar(conv->type);
	ft_putchar('\n');
	ft_putstr("len : ");
	ft_putnbr(conv->lenght);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_sbuild	*sb;
	t_sbuild	*temp;
	t_conv		conv;

	ft_parseformat(&conv, "-040i");
	ft_debugconv (&conv);
	//ft_putbits(conv.flags);
	// sb = ft_sbnew("");
	// char	c = 'a';
	// ft_sb_buildstr(&sb, "0123456789", 10);

	// temp = sb;
	// while (temp->next)
	// {
	// 	printf("str : [%s] next : (%p)\n", temp->str, temp->next);
	// 	temp = temp->next;
	// }
	// printf("str : [%s] next : (%p)\n", temp->str, temp->next);
	// printf("len : %i\n", ft_sblen(sb));

	// ft_sb_display(sb);
	printf("\ndone\n");
}
