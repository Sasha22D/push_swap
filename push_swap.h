#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h> // pour les printf des tests

typedef struct s_stack_node
{
	long 			value;
	int			index;
	bool			above_median;
	bool			cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}			t_stack_node;

char	**ft_split(char *str);
void	ft_init_stack(t_stack_node **stack, char **tab);
void	ft_lst_add_front(t_stack_node **stack, t_stack_node *new);
void	ft_lstdelone(t_stack_node *node);
void	swap_first_elements(t_stack_node **stack);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);

#endif