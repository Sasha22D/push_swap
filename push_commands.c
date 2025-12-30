/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:21:56 by sadaniel          #+#    #+#             */
/*   Updated: 2025/12/19 11:21:59 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_first_element(t_stack_node **stack_1, t_stack_node **stack_2)
{
	t_stack_node	*temp;
	t_stack_node	*head;

	temp = *stack_1;
	if ((*stack_1)->next)
	{
		*stack_1 = (*stack_1)->next;
		head = *stack_1;
	}
	else
		head = NULL;
	temp->prev = NULL;
	temp->next = *stack_2;
	*stack_2 = temp;
	*stack_1 = head;
	while (head != NULL)
	{
		head->index -= 1;
		head = head->next;
	}
	head = *stack_2;
	if (head->next)
	{
		head = head->next;
		head->prev = *stack_2;
		while (head != NULL)
		{
			head->index += 1;
			head = head->next;
		}
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push_first_element(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push_first_element(a, b);
	write(1, "pb\n", 3);
}
