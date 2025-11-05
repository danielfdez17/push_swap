

#include "../inc/headers/push_swap.h"

// static void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		ft_printf("%d ", stack->value);
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		++av;
	if (!init_stack(&a, av))
		return (0);
	size = get_size(a);
	if (!is_stack_sorted(a))
	{
		if (size == 2)
			sa(&a, 1);
		else if (size == 3)
			sort_three(&a, true);
		else if (size <= 50)
			selection_sort(&a, &b, true);
		else
			radix_sort(&a, &b, size, true);
	}
	if (!is_stack_sorted(a))
		ft_printf("Not sorted\n");
	// while (a)
	// {
	// 	ft_printf("%d ", a->value);
	// 	a = a->next;
	// }
	// while (b)
	// {
	// 	ft_printf("%d ", b->value);
	// 	b = b->next;
	// }
	// ft_printf("\n");
	free_stack(a);
	free_stack(b);
}
