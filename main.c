/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:21:49 by sadaniel          #+#    #+#             */
/*   Updated: 2025/12/19 11:21:54 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == 0))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1]);
		ft_init_stack(&a, argv);
	}
	else
		ft_init_stack(&a, argv + 1);
	if (!is_stack_sorted(&a))
	{
		if (get_stack_len(&a) == 2)
		{
			swap_first_elements(&a);
		}
		else if (get_stack_len(&a) == 3)
		{
			tiny_sort(&a);
		}
		else
			push_swap(&a, &b);
	}
	while (a != NULL)
	{
		printf("Value: %d, index: %d PRICE:%d\n", a->value, a->index, a->price);
		printf("ID: %p, Next: %p, prev: %p\n", (void*)a, (void*)a->next, (void*)a->prev);
		a = a->next;
	}
	printf("======================================\n");
	while (b != NULL)
	{
		printf("Value: %d, index: %d Target node:%d PRICE:%d\n", b->value, b->index, b->target_node->value, b->price);
		printf("ID: %p, Next: %p, prev: %p\n", (void*)b, (void*)b->next, (void*)b->prev);
		b = b->next;
	}
}
