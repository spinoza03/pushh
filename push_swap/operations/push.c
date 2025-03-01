/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:24:11 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/01 00:42:50 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src || !dst)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	if (!b || !*b)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
}
