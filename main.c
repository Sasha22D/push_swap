#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	// t_stack_node	*b;

	a = NULL;
	// b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == 0))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1]);
		ft_init_stack(&a, argv);
	}
	else
		ft_init_stack(&a, argv + 1);
	if (!is_stack_sorted(&a))
	{
		if (get_stack_len(&a) == 2)
		{
			swap_first_elements(&a);
		}
		else if (get_stack_len(&a) == 3)
		{
			tiny_sort(&a);
		}
	}
	// while (a != NULL)
	// {
	// 	printf("Value: %ld, index: %d\n", a->value, a->index);
	// 	printf("ID: %p, Next: %p, prev: %p\n", (void*)a, (void*)a->next, (void*)a->prev);
	// 	a = a->next;
	// }
	// printf("======================================\n");
	// while (b != NULL)
	// {
	// 	printf("Value: %ld, index: %d\n", b->value, b->index);
	// 	printf("ID: %p, Next: %p, prev: %p\n", (void*)b, (void*)b->next, (void*)b->prev);
	// 	b = b->next;
	// }
}