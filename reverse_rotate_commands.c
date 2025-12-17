#include "push_swap.h"

void	reverse_rotate_stack(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*tail;
	t_stack_node	*second;
	t_stack_node	*temp;

	if (!(*stack)->next)
		return ;
	head = *stack;
	tail = *stack;
	second = head->next;
	temp = second;
	while (tail->next)
		tail = tail->next;
	second->prev = NULL;
	head->prev = tail;
	head->next = NULL;
	head->index = tail->index + 1;
	tail->next = head;
	while (temp != NULL)
	{
		temp->index -= 1;
		temp = temp->next;
	}
	*stack = second;
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
}