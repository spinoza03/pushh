/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:24:11 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/25 11:32:26 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void push(t_stack **src, t_stack **dst)
{
	if (!src || !*src || !dst) // Ensure valid pointers
		return;
	t_stack *tmp = *src;
	*src = tmp->next;  // Move the head to the next element
	tmp->next = *dst;  // Insert at top of destination stack
	*dst = tmp;
}

void pb(t_stack **a, t_stack **b)
{
	if (!a || !*a) // Only check source stack
		return;
	push(a, b);
	write(1, "pb\n", 3);
}

void pa(t_stack **a, t_stack **b)
{
	if (!b || !*b) // Only check source stack
		return;
	push(b, a);
	write(1, "pa\n", 3);
}
