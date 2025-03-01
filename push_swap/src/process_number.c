/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:19:23 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/01 11:56:02 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

	if (!is_valid_integer(str))
		return (0);
	num = ft_atoi(str);
	if (!num)
		return (0);
	add_node(stack_a, (int)num);
	return (1);
}
