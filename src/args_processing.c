/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:48:28 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:48:30 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_duplicates(t_stack *stack)
{
	t_elem	*current;
	t_elem	*runner;

	current = stack->top;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
			{
				ft_putendl_fd("Error: duplicate numbers", STDERR_FILENO);
				free_stack(stack);
				return (false);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (true);
}

bool	process_arguments(int ac, char **av, t_stack *a)
{
	char	**numbers;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		numbers = ft_split(av[i], ' ');
		if (!numbers)
			continue ;
		j = -1;
		while (numbers[++j])
		{
			if (input_error(numbers[j]))
			{
				ft_putendl_fd("Error: invalid input", STDERR_FILENO);
				ft_free_split(numbers);
				free_stack(a);
				return (false);
			}
			push_bottom(a, new_elem(ft_atoi(numbers[j])));
		}
		ft_free_split(numbers);
	}
	return (check_duplicates(a));
}
