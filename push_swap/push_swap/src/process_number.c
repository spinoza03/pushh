/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:19:23 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/14 15:59:46 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	check_arr(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i])
// 		i++;
// 	if (i <= 1)
// 		return (0);
// 	return (1);
// }
int	is_valid_integer(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	process_numbers(char *str, t_stack **stack_a)
{
	long	num;
	int		error;

	if (!is_valid_integer(str))
		return (0);
	num = ft_atoi(str, &error);
	if (error || num < INT_MIN || num > INT_MAX)
		return (0);
	add_node(stack_a, (int)num);
	return (1);
}
