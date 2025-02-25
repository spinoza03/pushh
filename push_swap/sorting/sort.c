/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:24:07 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/25 10:44:59 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}
void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    if (is_sorted(*stack_a))
        return;
    int size = stack_size(*stack_a);
    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size <= 5)
        sort_four_or_five(stack_a, stack_b);
	else
		sort_large_stack(stack_a, stack_b);
}
 