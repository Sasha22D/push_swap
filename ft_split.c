#include "push_swap.h"

int	ft_count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
				count++;
		}
		i++;
	}
	return (count);
}

int	ft_strlen_sep(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *str)
{
	char	**new;
	int	i;
	int	j;

	i = 0;
	j = 0;
	new = malloc((ft_count_words(str) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			new[j] = ft_strdup(str + i);
			i += ft_strlen_sep(str + i);
			j++;
		}
	}
	new[j] = NULL;
	return (new);
}
