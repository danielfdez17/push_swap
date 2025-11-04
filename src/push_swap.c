

#include "../inc/headers/push_swap.h"

 // ! 80% = 100 en menos de 700 movimientos
 // ! 100% = 500 en menos de 5500 movimientos

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
	if (!init_stack(&a, av + 1))
		return (0);
	size = get_size(a);
	if (!is_stack_sorted(a))
	{
		if (size == 2)
			sa(&a, 1);
		else if (size == 3)
			sort_three(&a, true);
		else if (size <= 50)
			selection_sort(a, b, true);
		else
			radix_sort(&a, &b, size, true);
	}
	if (!is_stack_sorted(a))
		ft_printf("Not sorted!\n");
	free_stack(a);
	free_stack(b);
}
