#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argv == 2 && argv[1][0] == 0))
		return (1);
	if (argc == 2)
		argv = ft_split(argv + 1);
}