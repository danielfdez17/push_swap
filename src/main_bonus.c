#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	if (ac == 1 || (ac == 2 && !av[1][0]) || !process_arguments(ac, av, &a))
		return (0);
	if (!is_stack_sorted(&a))
		read_moves(&a, &b);
	if (!is_stack_sorted(&a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}