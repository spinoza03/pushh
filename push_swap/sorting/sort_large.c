/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:22:18 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/27 15:25:24 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
    int i = 0;
    int threshold = chunk_size;

    while (*stack_a)
    {
        if ((*stack_a)->index <= i)
        {
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

void move_max_to_top(t_stack **stack_b, int max_pos, int len)
{
    if (max_pos <= len / 2)
    {
        while (max_pos-- > 0)
            rb(stack_b);
    }
    else
    {
        while (max_pos++ < len)
            rrb(stack_b);
    }
}

void	push_back_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int		len;
	int		max_pos;
	t_stack	*tmp;
	int		i;

	while (*stack_b)
	{
		len = stack_size(*stack_b);
		tmp = *stack_b;
		max_pos = 0;
		i = 0;

		while (tmp)
		{
			if (tmp->index == len - 1)
			{
				max_pos = i;
				break ;
			}
			tmp = tmp->next;
			i++;
		}
		move_max_to_top(stack_b, max_pos, len);
		pa(stack_a, stack_b);
	}
}

void sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
    int chunk_size = get_chunk_size(stack_size(*stack_a));

    index_stack(stack_a);
    push_chunks(stack_a, stack_b, chunk_size);
    push_back_sorted(stack_a, stack_b);
}
