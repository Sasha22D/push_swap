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
	t_stack_node	*head_1;
	t_stack_node	*head_2;

	temp = *stack_1;
	*stack_1 = (*stack_1)->next;
	head_1 = *stack_1;
	(*stack_1)->prev = NULL;
	temp->next = *stack_2;
	*stack_2 = temp;
	while (head_1 != NULL)
	{
		head_1->index -= 1;
		head_1 = head_1->next;
	}
	head_2 = *stack_2;
	if (head_2->next)
	{
		head_2 = head_2->next;
		head_2->prev = *stack_2;
		while (head_2 != NULL)
		{
			head_2->index += 1;
			head_2 = head_2->next;
		}
	}
}
