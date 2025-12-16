#include "push_swap.h"

void	swap_first_elements(t_stack_node **stack)
{
	t_stack_node	*head;
	long	cpy_value;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		cpy_value = head->value;
		head->value = head->next->value;
		head->next->value = cpy_value;
	}

}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_first_elements(stack_a);
	swap_first_elements(stack_b);
}