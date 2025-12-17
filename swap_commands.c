#include "push_swap.h"

void	swap_first_elements(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if(!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;

	first->prev = second;
	first->next = third;
	first->index = 1;
	second->prev = NULL;
	second->next = first;
	second->index = 0;
	third->prev = first;

	*stack = second;
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_first_elements(stack_a);
	swap_first_elements(stack_b);
}
