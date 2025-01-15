/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:06 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/15 19:09:42 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/includes/libft.h"
#include "ft_string_builder.h"

#define TEST(name, format, ...) {\
	dprintf(1, "\n ======= TEST : %s : format:%s\n", name, format);\
	int a = dprintf(1, "printf    : "format, __VA_ARGS__);\
	int b = ft_printf("ft_printf : "format, __VA_ARGS__);\
	dprintf(1, "diff %d %d\n", a, b);\
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	// TEST("A", "[%+.13i]\n", (int)2147483617);

	// TEST("B", "[%-+13.i]\n",(int)2147483617);
	// TEST("C", "[%-012i]\n",(int)-2147483648);
	// TEST("D", "[%-012.i]\n",(int)-2147483648);
	// TEST("E", "[%- 12i]\n",(int)-2147483647);
	// TEST("F", "[%-16.14i]\n",(int)-2147483647);
	// TEST("G", "[%-014.16i]\n",(int)-2147483647);
	// TEST("F", "[%-.i]\n",(int)-2147483647);
	// TEST("G", "[%-.3i]\n",(int)-21);
	// TEST("G", "[%-3.2i]\n",(int)-21);
	TEST("G", "[%10.0i]\n",0);
	TEST("G", "[%10.0i]\n",0);
	TEST("G", "[%-08.p]\n",0);
	TEST("G", "[%0.i]\n",0);
	TEST("G", "[%0.1i]\n",0);
	TEST("G", "[%.5i]\n",0);

	// TEST("J", "[ %c %c %c ]\n", '2', '1', 0);
	// TEST("K", "[ %c %c %c ]\n", 0, '1', '2');

	// printf("[%.5i]\n", 0);
	// ft_printf("[%.5i]\n", 0);

	// printf("[%+.13i]\n", (int)2147483617);
	// ft_printf("[%+.13i]\n", (int)2147483617);


	printf("\ndone\n");
}

