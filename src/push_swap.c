

#include "../inc/headers/push_swap.h"

static void sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa(a, true);
	else if (size == 3)
		sort_three(a, true);
	else if (size <= MAX_SELECTION_NUMBER)
		selection_sort(a, b, true);
	else
		radix_sort(a, b, size, true);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		++av;
	if (!init_stack(&a, av))
		return (0);
	if (!is_stack_sorted(a))
		sort(&a, &b, get_size(a));
	free_stack(a);
	free_stack(b);
	return (0);
}
// ! checker_linux usage: ARG="9 8 7 6 5 4 3 2 1"; ./push_swap $ARG | ./checker_linux $ARG

