

#include "../inc/headers/push_swap.h"

t_bool	init_stack(t_stack **a, char **av)
{
	long	n;
	int		i;
	t_stack	*elem;

	i = 0;
	while (av && av[i])
	{
		if (syntax_error(av[i]))
			return (free_error(a));
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (free_error(a));
		if (duplicate_error(*a, (int)n))
			return (free_error(a));
		elem = stack_new((int)n);
		push_back(a, elem);
		++i;
	}
	return (true);
}
