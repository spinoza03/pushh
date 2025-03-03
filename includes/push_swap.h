/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:06:56 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/03 01:31:31 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		ft_isdigit(int c);
int		ft_atoi(const char *str, int *error);
char	**ft_split(const char *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

int		parse_args(int argc, char **argv, t_stack **stack_a);
int		is_valid_integer(char *str);
int		has_duplicates(t_stack *stack);
int		process_numbers(char *str, t_stack **stack_a);
void	free_array(char **arr);

t_stack	*stack_new_node(int value);
void	indexing(t_stack **stack);
void	add_node(t_stack **stack, int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
int		valid_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
int		get_chunk_size(int size);
void	index_stack(t_stack **stack);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_four_or_five(t_stack **stack_a, t_stack **stack_b);
void	move_largest_to_top(t_stack **stack_b, t_stack *largest);
void	move_to_top(t_stack **stack, t_stack *node);
void	sort_large_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

#endif