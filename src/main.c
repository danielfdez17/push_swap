/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:22 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 08:52:29 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

bool	read_input(int ac, char **av, t_stack **a)
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
				free_split(numbers);
				free_stack(a);
				return (false);
			}
			push_back(a, stack_new(ft_atoi(numbers[j])));
		}
		free_split(numbers);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]) || !read_input(ac, av, &a))
		return (0);
	if (!is_stack_sorted(a))
		sort(&a, &b, get_size(a));
	if (!is_stack_sorted(a))
		ft_printf("haha\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
// ! checker_linux usage: ARG="9 8 7 6 5 4 3 2 1";
// ./push_swap $ARG | ./checker_linux $ARG
