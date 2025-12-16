#include "push_swap.h"

void	push_first_element(t_stack_node **stack_1, t_stack_node **stack_2)
{
	t_stack_node	*temp;

	temp = (*stack_1)->next;
	ft_lst_add_front(stack_2, *stack_1);
	ft_lstdelone(*stack_1);
	*stack_1 = temp;
	(*stack_1)->prev = NULL;
	// while (*stack_1)
	// {
	// 	(*stack_1)->index -= 1;
	// 	*stack_1 = (*stack_1)->next;
	// }
	// while (*stack_2)
	// {
	// 	(*stack_2)->index -= 1;
	// 	*stack_2 = (*stack_2)->next;
	// }
}