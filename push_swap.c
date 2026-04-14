/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srichard <srichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:24:55 by srichard          #+#    #+#             */
/*   Updated: 2026/02/22 16:54:48 by srichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack		*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

static void	process_split(t_stack **stack_a, char **args)
{
	int		j;
	long	nbr;

	j = 0;
	while (args[j])
	{
		if (is_syntax_error(args[j]))
		{
			free_split(args);
			ft_error(stack_a);
		}
		nbr = ft_atol(args[j]);
		if (nbr < INT_MIN || nbr > INT_MAX || is_duplicate(*stack_a, (int)nbr))
		{
			free_split(args);
			ft_error(stack_a);
		}
		stack_add_back(stack_a, stack_new((int)nbr));
		j++;
	}
}

static void	parse_args(t_stack **stack_a, char **argv)
{
	int		i;
	char	**args;

	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			ft_error(stack_a);
		process_split(stack_a, args);
		free_split(args);
		i++;
	}
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = get_stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4 || size == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	parse_args(&stack_a, argv);
	if (stack_a == NULL)
		return (0);
	if (is_sorted(&stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	index_stack(&stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
