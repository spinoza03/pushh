/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:27:41 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/01 11:44:15 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_chunk_size(int len)
{
	if (len > 100)
		return (33);
	else
		return (16);
}

void	move_largest_to_top(t_stack **stack_b, t_stack *largest)
{
	int		position;
	t_stack	*temp;
	int		size;

	temp = *stack_b;
	position = 0;
	while (temp && temp != largest)
	{
		position++;
		temp = temp->next;
	}
	size = stack_size(*stack_b);
	if (position <= size / 2)
	{
		while (*stack_b != largest)
			rb(stack_b);
	}
	else
	{
		while (*stack_b != largest)
			rrb(stack_b);
	}
}

t_stack	*find_largest(t_stack *stack)
{
	t_stack	*largest;

	largest = stack;
	while (stack)
	{
		if (stack->value > largest->value)
			largest = stack;
		stack = stack->next;
	}
	return (largest);
}

void	move_to_top(t_stack **stack, t_stack *node)
{
	int		pos;
	int		size;
	t_stack	*tmp;

	pos = 0;
	size = stack_size(*stack);
	tmp = *stack;
	while (tmp && tmp != node)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
	{
		while (*stack != node)
			ra(stack);
	}
	else
	{
		while (*stack != node)
			rra(stack);
	}
}
