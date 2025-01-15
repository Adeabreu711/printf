/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:06 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/14 16:01:02 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/includes/libft.h"
#include "ft_string_builder.h"

#define TEST(name, format, ...) {\
	dprintf(1, "\n ======= TEST : %s : format:%s\n", name, format);\
	int a = dprintf(1, "0"format, __VA_ARGS__);\
	int b = ft_printf("1"format, __VA_ARGS__);\
	dprintf(1, "diff %d %d\n", a, b);\
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	//TEST("A", "[%-1.6i]\n", 5000);

	// TEST("F", "[ %c %c %c ]\n", '0', 0, '1');
	// TEST("J", "[ %c %c %c ]\n", '2', '1', 0);
	// TEST("K", "[ %c %c %c ]\n", 0, '1', '2');

	printf("[% +i]\n", 50);
	ft_printf("[% +i]\n", 50);

	printf("\ndone\n");
}

