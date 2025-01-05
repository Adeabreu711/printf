/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:06 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/04 20:15:11 by alde-abr         ###   ########.fr       */
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
	// t_sbuild	*sb;
	// t_conv		conv;

	//char str[7] = "%1%2%3";

	//sb = ft_sbnew("");
	////printf("writed : %i\n", ft_parseformat(&conv, "%s"));
	//ft_debugconv (&conv);
	//printf("%i\n", ft_atoi("1s"));
	// ft_pfbuildchar(sb, &conv, 't');
	//ft_pfbuildstr(sb, &conv, "test");

	// ft_sb_display(sb);
	// ft_printf("%  - -0.1c0. s", "test");
	// printf("\n[% - -0.1c0. s]", NULL);
	// printf("[%0.2i]\n", 3);
	//ft_printf("[%+17i]\n", 1);
	//printf("[%+17i]\n", 1);
	ft_printf("%8d", 0);
	printf("[%8d]", 0);

	// printf("\n[%-   0. 10z. s]", NULL);
	// printf("\n[% - -0.1z0. s]", NULL);
	// printf("\n[% - -0.1z0. s]", NULL);
	//printf("[%6s]\n", "test"); //[-] [ ]
	//ft_parseformat(&conv, "-040s");
	//ft_debugconv (&conv);
	//ft_putbits(conv.flags);
	//sb = ft_sbnew("");
	// char	c = 'a';
	//ft_sb_buildstr(&sb, "0123456789", 10);

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
