/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:21:35 by sadaniel          #+#    #+#             */
/*   Updated: 2025/12/19 11:21:42 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	get_target_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*head_a;
	t_stack_node	*head_b;

	head_a = *a;
	head_b = *b;
	head_b->target_node = NULL;
	while (head_b != NULL)
	{
		while (head_a != NULL)
		{
			if (head_b->value < head_a->value)
			{
				if (head_b->target_node)
				{
					if (head_b->target_node->value > head_a->value)
						head_b->target_node = head_a;
				}
				else
					head_b->target_node = head_a;
			}
			head_a = head_a->next;
		}
		if (head_b->target_node == NULL)
			head_b->target_node = find_smallest(a);
		head_a = *a;
		head_b = head_b->next;
	}
}

void	set_median(t_stack_node **a, t_stack_node **b)
{
	int			len;
	t_stack_node	*head;

	len = get_stack_len(a);
	head = *a;
	while (head != NULL)
	{
		if (head->index <= (len / 2))
			head->above_median = true;
		else
			head->above_median = false;
		head = head->next;
	}
	len = get_stack_len(b);
	head = *b;
	while (head != NULL)
	{
		if (head->index > (len / 2))
			head->above_median = false;
		else
			head->above_median = true;
		head = head->next;
	}
}

void	set_price(t_stack_node **a, t_stack_node **b)
{
	int			len;
	t_stack_node	*head;

	len = get_stack_len(a);
	head = *a;
	while (head != NULL)
	{
		if (head->above_median)
			head->price = head->index;
		else
			head->price = len - head->index;
		head = head->next;
	}
	len = get_stack_len(b);
	head = *b;
	while (head != NULL)
	{
		if (head->above_median)
			head->price = head->index;
		else
			head->price = len - head->index;
		head = head->next;
	}
}

void	find_cheapest(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*cursor;

	head = *stack;
	cursor = *stack;
	cursor->cheapest = true;
	while (head != NULL)
	{
		if (head->price + head->target_node->price < cursor->price + cursor->target_node->price)
		{
			cursor->cheapest = false;
			cursor = head;
			cursor->cheapest = true;
		}
		head = head->next;
	}
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*head;

	while (get_stack_len(a) > 3)
	{
		push_first_element(a, b);
	}
	head = *b;
	get_target_node(a, b);
	while (head != NULL)
	{
		set_median(a, b);
		set_price(a, b);
		// find_cheapest(b);
		head = head->next;
	}
}
