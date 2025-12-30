#include "push_swap.h"

void	free_stack(t_stack_node **a)
{
	t_stack_node	*head;
	t_stack_node	*temp;

	if (!*a)
		return ;
	head = *a;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	*a = NULL;
}

void	free_argv(char **tab)
{
	int	i;

	i = 0;
	if (!*tab || !tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

int	repetition_check(t_stack_node **stack, int nb)
{
	if (!stack)
		return (0);
	while (*stack)
	{
		if ((*stack)->value == nb)
			return (1);
		(*stack) = (*stack)->next;
	}
	return (0);
}

int	syntax_check(char *nbr)
{
	if (*nbr != '+' || *nbr != '-' || (*nbr < '0' && *nbr > 9))
		return (1);
	if ((*nbr == '+' || *nbr == '-') && (nbr[1] < '0' && nbr[1] > '9'))
		return (1);
	while (*nbr)
	{
		if (*nbr < '0' && *nbr > '9')
			return (1);
	}
	return (0);
}
