/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:22:06 by srichard          #+#    #+#             */
/*   Updated: 2026/02/22 16:52:42 by srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_stack **stack, int val)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*head;
	int		max;

	head = *stack_a;
	max = head->index;
	if (head->next->index > max)
		max = head->next->index;
	if (head->next->next->index > max)
		max = head->next->next->index;
	if ((*stack_a)->index == max)
		ra(stack_a);
	else if (head->next->index == max)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

static int	get_distance(t_stack **stack, int min_index)
{
	t_stack	*tmp;
	int		distance;

	distance = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == min_index)
			break ;
		distance++;
		tmp = tmp->next;
	}
	return (distance);
}

static void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		distance;
	int		size;

	min = get_min(stack_a, -1);
	distance = get_distance(stack_a, min);
	size = get_stack_size(*stack_a);
	if (distance <= size / 2)
	{
		while ((*stack_a)->index != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != min)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = get_stack_size(*stack_a);
	while (size > 3)
	{
		push_smallest_to_b(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
