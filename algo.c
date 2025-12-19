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

void	get_target_node(t_stack_node **a, t_stack_node **node)
{
	t_stack_node	*head;

	head = *a;
	(*node)->target_node = NULL;
	while (head != NULL)
	{
		if ((*node)->value < head->value)
		{
			if ((*node)->target_node)
			{
				if ((*node)->target_node->value > head->value)
					(*node)->target_node = head;
			}
			else
				(*node)->target_node = head;
		}
		head = head->next;
	}
	if ((*node)->target_node == NULL)
		(*node)->target_node = find_smallest(a);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*head;

	while (get_stack_len(a) > 3)
	{
		push_first_element(a, b);
	}
	head = *b;
	if (get_stack_len(a) == 3)
		tiny_sort(a);
	while (head != NULL)
	{
		get_target_node(a, &head);
		head = head->next;
	}
}
