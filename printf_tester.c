#include "libft.h"
#include "ft_printf.h"
#include "stdio.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648


int	main(int argc, char *argv[])
{
	char *empty = "";
	char *nil = NULL;
	char *robot = "bLiP BloOop !";

	// %s
	ft_printf("RESULT   : [%s]\n", robot);
	printf("EXPECTED : [%s]\n\n", robot);

	ft_printf("RESULT   : [%s]\n", nil);
	printf("EXPECTED : [%s]\n\n", nil);

	ft_printf("RESULT   : [%s]\n", empty);
	printf("EXPECTED : [%s]\n\n", empty);

	ft_printf("RESULT   : [%s] [%s] [%s] [%s] [%s] [%s]\n", empty, empty, robot, robot, nil, nil);
	printf("EXPECTED : [%s] [%s] [%s] [%s] [%s] [%s]\n", empty, empty, robot, robot, nil, nil);

	ft_printf("%s%\n",robot);
	printf("%s%\n", robot);
}
