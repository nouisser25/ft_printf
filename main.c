#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	a;
	int	r1;
	int	r2;

	a = 14;
	r1 = ft_printf("%d|%s|%c|%p|%u|%x|%X|%%|%i\n",
			a, "hi", 'z', &a, 42u, 255, 255, INT_MIN);
	r2 = printf("%d|%s|%c|%p|%u|%x|%X|%%|%i\n",
			a, "hi", 'z', &a, 42u, 255, 255, INT_MIN);
	printf("%d %d\n", r1, r2);
	return (0);
}
