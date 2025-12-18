#include "push_swap.h"

void	reverse_rotate_stack(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tail;

	head = *stack;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	tail->index = 0;
	head->prev = tail;
	while (head != NULL)
	{
		head->index += 1;
		head = head->next;
	}
	*stack = tail;
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
}