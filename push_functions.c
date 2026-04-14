/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:10:38 by srichard          #+#    #+#             */
/*   Updated: 2026/02/22 16:54:35 by srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (!dest)
	{
		*dest = tmp;
		(*dest)->next = NULL;
	}
	else
	{
		tmp->next = *dest;
		*dest = tmp;
	}
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	return (0);
}
