/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:22:18 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/25 11:54:44 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
	else
		return (size / 11);
}
void	push_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	i;
	int	threshold;

	threshold = chunk_size;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			if (!*stack_a)
    			return;
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + threshold))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

int	find_max_position(t_stack *stack)
{
	int		max;
	int		pos;
	int		index;
	t_stack	*tmp;

	tmp = stack;
	max = tmp->index;
	pos = 0;
	index = 0;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (pos);
}
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	len;

	while (*stack_b)
	{
		len = stack_size(*stack_b);
		pos = find_max_position(*stack_b);
		if (pos <= len / 2)
		{
			while (pos-- > 0)
				rb(stack_b);
		}
		else
		{
			while (pos++ < len)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
void	sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*stack_a);
	indexing(stack_a);
	chunk_size = get_chunk_size(size);
	push_chunks(stack_a, stack_b, chunk_size);
	push_back_to_a(stack_a, stack_b);
}
