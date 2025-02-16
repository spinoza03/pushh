/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:26:55 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/14 16:19:19 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	process_single_argument(char *arg, t_stack **stack_a)
{
	char	**arr;
	int		success;
	int		i;

	if (arg[0] == '\0') 
		return (0);
	arr = ft_split(arg, ' ');
	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		success = process_numbers(arr[i], stack_a);
		if (!success)
		{
			free_array(arr);
			return (0);
		}
		if (!arr[i])
			return (0);
		i++;
	}
	free_array(arr);
	return (1);
}

int	parse_args(int ac, char **av, t_stack **stack_a)
{
	int		i;
	int		success;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '"' && av[i][ft_strlen(av[i]) - 1] == '"')
		{
			av[i][ft_strlen(av[i]) - 1] = '\0';
			av[i] = av[i] + 1;
			success = process_single_argument(av[i], stack_a);
		}
		else
		{
			success = process_single_argument(av[i], stack_a);
		}
		if (!success)
			return (stack_clear(stack_a), 0);
		i++;
	}
	if (!valid_stack(*stack_a))
		return (stack_clear(stack_a), 0);
	if (has_duplicates(*stack_a))
		return (stack_clear(stack_a), 0);
	return (1);
}
