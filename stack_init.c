/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:22:14 by sadaniel          #+#    #+#             */
/*   Updated: 2025/12/19 11:22:18 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static long	ft_atol(char *str)
{
	long	result;
	long	sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}

static t_stack_node	*ft_lst_new(long value, int index)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void	ft_lst_add_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*tail;

	if (!stack || !new)
		return ;
	tail = *stack;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	while (tail->next)
		tail = tail->next;
	tail->next = new;
	new->prev = tail;
}

void	ft_init_stack(t_stack_node **stack, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_lst_add_back(stack, ft_lst_new(ft_atol(tab[i]), i));
		i++;
	}
}
