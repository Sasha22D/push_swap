#include "push_swap.h"

static void	set_target_node(t_stack_node **a, t_stack_node **b)
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

static void	set_median(t_stack_node **a, t_stack_node **b)
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

static void	set_price(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*head;
	int		len;

	head = *a;
	len = get_stack_len(a);
	while (head)
	{
		if (head->above_median)
			head->price = head->index;
		else
			head->price = len - head->index;
		head = head->next;
	}
	head = *b;
	len = get_stack_len(b);
	while (head)
	{
		if (head->above_median)
			head->price = head->index;
		else
			head->price = len - head->index;
		head = head->next;
	}
}

static void	set_cheapest(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*cursor;

	head = *stack;
	cursor = head;
	cursor->cheapest = true;
	cursor->target_node->cheapest = true;
	while (head)
	{
		if (head->price + head->target_node->price <
			cursor->price + cursor->target_node->price)
		{
			cursor->cheapest = false;
			cursor->target_node->cheapest = false;
			cursor = head;
			cursor->cheapest = true;
			cursor->target_node->cheapest = true;
		}
		head = head->next;
	}
}

void	init_nodes_values(t_stack_node **a, t_stack_node **b)
{
	set_target_node(a, b);
	set_median(a, b);
	set_price(a, b);
	set_cheapest(b);
}