#include "push_swap.h"

void	rotate_stack(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tail;

	head = *stack;
	tail = *stack;
	while (tail != NULL)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	while (head != NULL)
	{
		head->index += 1;
		head = head->next;
	}
	*stack = tail;
}