/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:11:02 by srichard          #+#    #+#             */
/*   Updated: 2026/02/22 16:57:03 by srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = *stack;
	while (tail ->next)
		tail = tail->next;
	tail->next = tmp;
	tmp->next = NULL;
}

int	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return (0);
}
