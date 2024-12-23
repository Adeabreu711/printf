/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:06 by alde-abre         #+#    #+#             */
/*   Updated: 2024/12/23 19:37:17 by alde-abre        ###   ########.fr       */
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
	ft_putchar('\n');
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_sbuild	*sb;
	t_conv		conv;

	// char str[10] = "0123456789";

	// sb = ft_sbnew("");
	// printf("writed : %i\n", ft_parseformat(&conv, "%-4c"));
	// ft_pfbuildchar(sb, &conv, 't');

	// ft_sb_display(sb);

	ft_printf("test%cb b", 0);
	printf("\n[test%cb b]", 0);

	//printf("[%3c]\n", 't');
	// printf("[%10c]\n",'c');
	// printf("[%-10c]\n",'c');
	//printf("[%-1.5s]\n","test");

	// printf("[%-10.4i]\n", 10);
	// printf("test : [%i]\n", !!0);
	//printf("[%c]", 0);

	// ft_parseformat(&conv, "-040i");
	// ft_debugconv (&conv);
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
