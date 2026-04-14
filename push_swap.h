/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:25:10 by srichard          #+#    #+#             */
/*   Updated: 2026/02/22 16:55:03 by srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// utils
void	ft_error(t_stack **stack_a);
long	ft_atol(const char *str);
int		is_syntax_error(char *str_n);
int		is_duplicate(t_stack *a, int n);
int		is_sorted(t_stack **stack);
char	**ft_split(char *s, char c);
void	free_split(char **split);

// stack
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	free_stack(t_stack **stack);

// index.c
void	index_stack(t_stack **stack);

// swap_functions.c
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);

// push_functions.c
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);

// rotate_functions.c
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);

// reverse_functions.c
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

//radix.c
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
int		get_stack_size(t_stack *stack);

// simple_sort.c
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

#endif
