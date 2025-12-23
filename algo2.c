#include "push_swap.h"

t_stack_node	*get_cheapest_node(t_stack_node **stack)
{
	t_stack_node	*head;

	head = *stack;
	while (head != NULL)
	{
		if (head->cheapest == true)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	rotate_cheapest(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (!(*stack_a)->cheapest && !(*stack_b)->cheapest)
		rr(stack_a, stack_b);
	while (!(*stack_a)->cheapest)
		rotate_stack(stack_a);
	while (!(*stack_b)->cheapest)
		rotate_stack(stack_b);
}

void	reverse_rotate_cheapest(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (!(*stack_a)->cheapest || !(*stack_b)->cheapest)
		rrr(stack_a, stack_b);
	while (!(*stack_a)->cheapest)
		reverse_rotate_stack(stack_a);
	while (!(*stack_b)->cheapest)
		reverse_rotate_stack(stack_b);
}

void	rotate_push(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(stack_b);
	if (cheapest_node->above_median &&
		cheapest_node->target_node->above_median)
		rotate_cheapest(stack_a, stack_b);
	else if (!(cheapest_node->above_median) &&
		!(cheapest_node->target_node->above_median))
		reverse_rotate_cheapest(stack_a, stack_b);
	else
	{
		if (cheapest_node->target_node->above_median)
		{
			while (!((*stack_a)->cheapest))
				rotate_stack(stack_a);
		}
		else
		{
			while (!((*stack_a)->cheapest))
				reverse_rotate_stack(stack_a);
		}
		if (cheapest_node->above_median)
		{
			while (!((*stack_b)->cheapest))
				rotate_stack(stack_b);
		}
		else
		{
			while (!((*stack_b)->cheapest))
				reverse_rotate_stack(stack_b);
		}
	}
	push_first_element(stack_b, stack_a);
}