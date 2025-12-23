#include "push_swap.h"

void	set_target_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*head;
	t_stack_node	*head_b;

	head_b = *b;
	while (head_b)
	{
		head = *a;
		while (head != NULL)
		{
			if (head->value > head_b->value)
			{
				if (head_b->target_node && head_b->target_node->value > head->value)
				{
					head_b->target_node = head;
				}
				else if (!(head_b->target_node))
				{
					head_b->target_node = head;
				}
			}
			head = head->next;
		}
		if (!(head_b->target_node))
			head_b->target_node = find_smallest(a);
		head_b = head_b->next;
	}
}

void	set_median(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*head;
	int		len;

	head = *a;
	len = get_stack_len(a);
	while (head)
	{
		if (head->index <= (len / 2))
			head->above_median = true;
		else
			head->above_median = false;
		head = head->next;
	}
	head = *b;
	len = get_stack_len(b);
	while (head)
	{
		if (head->index <= (len / 2))
			head->above_median = true;
		else
			head->above_median = false;
		head = head->next;
	}
}