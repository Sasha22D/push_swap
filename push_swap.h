#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack_node
{
	int 			value;
	int			index;
	bool			above_median;
	bool			cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}			t_stack_node;

char	**ft_split(char *str);
void	ft_init_stack(t_stack_node **stack, char **tab);

#endif