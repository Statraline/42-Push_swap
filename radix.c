/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:02:45 by srichard          #+#    #+#             */
/*   Updated: 2026/02/22 16:55:38 by srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	process_bit(t_stack **stack_a, t_stack **stack_b, int i, int size)
{
	int		j;
	t_stack	*head;

	j = 0;
	while (j < size)
	{
		head = *stack_a;
		if (((head->index >> i) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		j++;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		size;
	int		max_bits;

	i = 0;
	size = get_stack_size(*stack_a);
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		process_bit(stack_a, stack_b, i, size);
		while (get_stack_size(*stack_b) > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
