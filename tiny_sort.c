#include "push_swap.h"

int	is_stack_sorted(t_stack_node **stack)
{
	t_stack_node	*head;

	head = *stack;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_stack_len(t_stack_node **stack)
{
	int	len;
	t_stack_node	*head;

	len = 0;
	head = *stack;
	while (head != NULL)
	{
		len += 1;
		head = head->next;
	}
	return (len);
}

t_stack_node	*find_biggest(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tail;
	head = *stack;
	tail = head->next;
	if (head->value > tail->value)
	{
		tail = tail->next;
		if (head->value > tail->value)
			return (head);
		else
			return (tail);
	}
	else
	{
		head = head->next;
		tail = tail->next;
		if (head->value > tail->value)
			return (head);
		else
			return (tail);
	}
}

void	tiny_sort(t_stack_node **stack)
{
	t_stack_node	*biggest;

	biggest = find_biggest(stack);
	if (*stack == biggest)
		rotate_stack(stack);
	else if ((*stack)->next == biggest)
		reverse_rotate_stack(stack);
	if ((*stack)->value > (*stack)->next->value)
		swap_first_elements(stack);
}