/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:22:01 by sadaniel          #+#    #+#             */
/*   Updated: 2025/12/19 11:22:04 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> // pour les printf des tests

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}			t_stack_node;

char	**ft_split(char *str);
void	ft_init_stack(t_stack_node **stack, char **tab);
// SWAP FIRST ELEMENTS COMMANDS
void	swap_first_elements(t_stack_node **stack);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);
// PUSH FIRST ELEMENT COMMAND
void	push_first_element(t_stack_node **stack_1, t_stack_node **stack_2);
// ROTATE COMMANDS
void	rotate_stack(t_stack_node **stack);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b);
// REVERSE ROTATE COMMANDS
void	reverse_rotate_stack(t_stack_node **stack);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b);
// CHECK STACK AND TINY SORT
int		is_stack_sorted(t_stack_node **stack);
int		get_stack_len(t_stack_node **stack);
t_stack_node	*find_biggest(t_stack_node **stack);
t_stack_node	*find_smallest(t_stack_node **stack);
void	tiny_sort(t_stack_node **stack);
// ALGORITHM
void	push_swap(t_stack_node **a, t_stack_node **b);
void	init_nodes_values(t_stack_node **a, t_stack_node **b);
void	push_cheapest(t_stack_node **a, t_stack_node **b);
// ERROR HANDLING
void	free_stack(t_stack_node **a);
void	free_argv(char **tab);
int	repetition_check(t_stack_node **stack, int nb);
int	syntax_check(char *nbr);

#endif
