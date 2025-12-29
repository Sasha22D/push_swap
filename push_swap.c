#include "push_swap.h"

static void	set_target_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*head_a;
	t_stack_node	*head_b;
	t_stack_node	*best;

	head_b = *b;
	while (head_b)
	{
		best = NULL;
		head_a = *a;
		while (head_a)
		{
			if (head_a->value > head_b->value)
			{
				if (!best || head_a->value < best->value)
					best = head_a;
			}
			head_a = head_a->next;
		}
		if (!best)
			best = find_smallest(a);
		head_b->target_node = best;
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

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;

	while (get_stack_len(a) > 3)
		push_first_element(a, b);
	tiny_sort(a);
	while (*b)
	{
		init_nodes_values(a, b);
		t_stack_node *head = *b;
		while (head)
		{
			printf("%d NODE ----> TARGET= %d\n", head->value, head->target_node->value);
			head = head->next;
		}
		push_cheapest(a, b);
		
	}
	smallest = find_smallest(a);
	while (*a != smallest)
	{
		if (smallest->above_median)
			rotate_stack(a);
		else
			reverse_rotate_stack(a);
	}
}