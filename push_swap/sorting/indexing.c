/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:38:37 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/25 10:38:52 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*cmp;
	int		index;

	tmp = *stack;
	while (tmp)
	{
		cmp = *stack;
		index = 0;
		while (cmp)
		{
			if (tmp->value > cmp->value)
				index++;
			cmp = cmp->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}
