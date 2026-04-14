/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:10:26 by srichard          #+#    #+#             */
/*   Updated: 2026/02/22 16:53:53 by srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*current;
	int		count;

	head = *stack;
	while (head)
	{
		count = 0;
		current = *stack;
		while (current)
		{
			if (current->value < head->value)
				count++;
			current = current->next;
		}
		head->index = count;
		head = head->next;
	}
}
