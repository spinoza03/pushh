/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:01:22 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/14 16:29:07 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_node(t_stack **stack_a, int value)
{
	t_stack	*new_node;

	new_node = stack_new_node(value);
	if (!new_node)
		return;
	stack_add_back(stack_a, new_node);
}
int valid_stack(t_stack *stack)
{
	t_stack *current;
	int		i;

	i = 0;
	current = stack;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i >= 1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*run;

	current = stack;
	while (current)
	{
		run = current->next;
		while (run)
		{
			if (current->value == run->value)
				return (1);
			run = run->next;
		}
		current = current->next;
	}
	return (0);
}
char	*join_args(int ac, char **av)
{
	int i;
	char *p;
	char *tmp;

	if (ac < 3)
		return (ft_strdup(av[1]));
	p = ft_strdup(av[1]);
	if (!p)
		return (NULL);
	i = 2;
	while (ac > i)
	{
		tmp = p;
		p = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!p)
			return (NULL);
		i++;
	}
	return (p);
	free(p);
}