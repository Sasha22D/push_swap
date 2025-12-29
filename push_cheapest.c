#include "push_swap.h"

static t_stack_node	*get_cheapest(t_stack_node **stack)
{
	t_stack_node	*head;

	head = *stack;
	while (head)
	{
		if (head->cheapest)
			return (head);
		head = head->next;
	}
	return (head);
}

static void	rotate_cheapest(t_stack_node **stack, t_stack_node *cheapest)
{
	if (cheapest->above_median)
	{
		while (*stack != cheapest)
			rotate_stack(stack);
	}
	else
	{
		while (*stack != cheapest)
			reverse_rotate_stack(stack);
	}
}

void	push_cheapest(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rr(a, b);
	}
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
	{
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rrr(a, b);
	}
	rotate_cheapest(a, cheapest_node->target_node);
	rotate_cheapest(b, cheapest_node);
	(*a)->cheapest = false;
	(*b)->cheapest = false;
	push_first_element(b, a);
}