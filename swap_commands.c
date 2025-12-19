/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:22:19 by sadaniel          #+#    #+#             */
/*   Updated: 2025/12/19 11:22:23 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_first_elements(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if(!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	if (third)
	{
		third->prev = first;
		first->next = third;
	}
	else
		first->next = NULL;
	first->prev = second;
	first->index = 1;
	second->prev = NULL;
	second->next = first;
	second->index = 0;

	*stack = second;
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_first_elements(stack_a);
	swap_first_elements(stack_b);
}
