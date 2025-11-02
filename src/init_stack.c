

#include "../inc/headers/push_swap.h"

void	init_stack(t_stack **a, char **av)
{
	long	n;
	int		i;
	t_stack	*elem;

	i = 0;
	while (av && av[i])
	{
		if (syntax_error(av[i]))
			free_error(a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a);
		if (duplicate_error(*a, (int)n))
			free_error(a);
		elem = list_new((int)n);
		push_back(a, elem);
		++i;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *node, char stack_name)
{
	while (stack && *stack != node)
	{
		if (stack_name == A)
		{
			if (node->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == B)
		{
			if (node->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}