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
		free_argv(argv);
	}
	else
		ft_init_stack(&a, argv + 1);
	if (!is_stack_sorted(&a))
	{
		if (get_stack_len(&a) == 2)
		{
			sa(&a);
		}
		else if (get_stack_len(&a) == 3)
		{
			tiny_sort(&a);
		}
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	// if (is_stack_sorted(&a))
	// 	printf("Sorted!\n");
	// while (a != NULL)
	// {
	// 	printf("NODE NUMBER %d\n=============\n", a->index);
	// 	printf("Value: %d, index: %d PRICE:%d CHEAPEST:%d\n", a->value, a->index, a->price, a->cheapest);
	// 	printf("ID: %p, Next: %p, prev: %p\n", (void*)a, (void*)a->next, (void*)a->prev);
	// 	a = a->next;
	// }
	// printf("======================================\n");
}
