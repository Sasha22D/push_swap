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

static void	rotate_cheapest(t_stack_node **stack, t_stack_node *cheapest, char c)
{
	if (cheapest->above_median)
	{
		if (c == 'a')
		{
			while (*stack != cheapest)
				ra(stack);
		}
		else
		{
			while (*stack != cheapest)
				rb(stack);
		}
	}
	else
	{
		if (c == 'a')
		{
			while (*stack != cheapest)
				rra(stack);
		}
		else
		{
			while (*stack != cheapest)
				rrb(stack);
		}
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
	rotate_cheapest(a, cheapest_node->target_node, 'a');
	rotate_cheapest(b, cheapest_node, 'b');
	(*a)->cheapest = false;
	(*b)->cheapest = false;
	pa(a, b);
}