/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:05:46 by sadaniel          #+#    #+#             */
/*   Updated: 2025/12/30 16:05:50 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	int				len;
	t_stack_node	*head;

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
	int				len;
	t_stack_node	*head;

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
		if (head->price + head->target_node->price
			< cursor->price + cursor->target_node->price)
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
