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
	*stack_1 = temp->next;
	temp->prev = NULL;
	temp->next = *stack_2;
	*stack_2 = temp;
	if ((*stack_2)->next)
		(*stack_2)->next->prev = *stack_2;
	head = *stack_1;
	while (head != NULL)
	{
		head->index -= 1;
		head = head->next;
	}
	head = (*stack_2)->next;
	while (head != NULL)
	{
		head->index += 1;
		head = head->next;
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
